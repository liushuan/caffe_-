#ifndef LOAD_MODEL_H
#define LOAD_MODEL_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <utility>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctime>
#include<cstdlib>

#include <caffe/caffe.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

#include "crc32.h"
#include "rc6_c.h"

typedef struct File_Firmware_Format_
{
    int file_type_flag;             /* FILE_TYPE_FLAG */
    long src_file_length;
    unsigned int src_file_crc32_check;
    long enc_file_length;
    unsigned int enc_file_crc32_check;
    char res[512];
}File_Firmware_Format;

class Encryption
{
public:
	static bool fill_rand_data(unsigned char *fill_buffer, unsigned int fill_data);	//字节对齐

	static void encryption_model(std::string prototxtFile, std::string caffemodelFile, std::string outputfile);

	static bool decrypt_model(std::string encryption_model, std::string &prototxt_string, std::string &model_string);

	static void load_model(std::string prototxt_string,std::string model_string, boost::shared_ptr<caffe::Net<float>> &_net);
};

#endif 
