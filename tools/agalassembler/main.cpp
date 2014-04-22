#include <iostream>
#include "agal_assembler.h"
#include <ghl_log.h>
#include <fstream>
#include <ghl_data_impl.h>

using namespace std;

GHL_API void GHL_CALL GHL_Log( GHL::LogLevel level,const char* message) {
    std::cout << message << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
            std::string contentv;
            {
                std::ifstream in(argv[1]);
                if (!in) {
                    std::cout << "failed opening " << argv[1] << std::endl;
                    return 1;
                }
                while (!in.eof()) {
                    std::string line;
                    std::getline(in,line);
                    contentv = contentv + line + "\n";
                }
            }
            GHL::ConstInlinedData srcv((const GHL::Byte*)contentv.c_str(),contentv.length());

            std::string contentf;
            {
                std::ifstream in(argv[2]);
                if (!in) {
                    std::cout << "failed opening " << argv[2] << std::endl;
                    return 1;
                }
                while (!in.eof()) {
                    std::string line;
                    std::getline(in,line);
                    contentf = contentf + line + "\n";
                }
            }
            GHL::ConstInlinedData srcf((const GHL::Byte*)contentf.c_str(),contentf.length());

            GHL::AGALData data;
            GHL::AGALAssembler assembler(&data);
            if (assembler.parse(&srcv,&srcf)) {
                std::cout << "success" << std::endl;
                return 0;
            }

            std::cout << "failed" << std::endl;
            return 1;
    }

    else
    {
            cout << "Use: filename_v filename_f" << endl;
            return 1;
    }
    return 0;
}

