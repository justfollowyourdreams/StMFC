#include "convert.hpp"

void convert(const std::string &path) {
    SF_INFO inFileInfo;
    SF_INFO outFileInfo;
    SNDFILE *inFile = sf_open(path.c_str(), SFM_READ, &inFileInfo);
    if (inFile == nullptr)
        throw FileNotOpenedException(path);
    else if (inFileInfo.channels != 2) {
        sf_close(inFile);
        throw NotStereoException();
    }

    float *inData = new float[inFileInfo.frames * 2];
    float *outData = new float[inFileInfo.frames];
    sf_readf_float(inFile, inData, inFileInfo.frames);
    for (int e = 0; e < inFileInfo.frames; e++) {
        for (int i = 0; i < 2; i++)
            outData[e] += inData[e * 2 + i];
        outData[e] /= 2;
    }
    outFileInfo = inFileInfo;
    outFileInfo.channels = 1;
    std::string outName;
    outName = path.substr(0, path.length() - 4);
    outName.append("_mono.wav");
    SNDFILE *outFile = sf_open(outName.c_str(), SFM_WRITE, &outFileInfo);
    if (outFile == nullptr) {
        sf_close(inFile);
        sf_close(outFile);
        delete[] inData;
        delete[] outData;
        throw FileNotCreatedException(outName);
    }
    sf_writef_float(outFile, outData, inFileInfo.frames);
    delete[] inData;
    delete[] outData;
    sf_close(inFile);
    sf_close(outFile);
}