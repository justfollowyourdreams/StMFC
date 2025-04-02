// Stolen and adapted from https://gist.github.com/nicolamontecchio/622276

#include "convert.hpp"

void convert(const std::string &path) {
    SNDFILE* sndfile;
    SF_INFO sfinfo;
    sndfile = sf_open(path.c_str(), SFM_READ, &sfinfo);
    if (sndfile == nullptr)
        throw FileNotOpenedException(path);
    else if (sfinfo.channels != 2) {
        sf_close(sndfile);
        throw NotStereoException();
    }

    float *audioIn = new float[sfinfo.channels * sfinfo.frames];
    sf_read_float(sndfile, audioIn, sfinfo.channels * sfinfo.frames);
    // mixdown
    float *audioOut = new float[sfinfo.frames];
    for(int i = 0; i < sfinfo.frames; i++)
    {
        audioOut[i] = 0;
        for(int j = 0; j < sfinfo.channels; j++)
            audioOut[i] += audioIn[i*sfinfo.channels + j];
        audioOut[i] /= sfinfo.channels;
    }
    sf_close(sndfile);
    // write output
    int frames = sfinfo.frames;
    sfinfo.channels = 1;

    std::string outName;
    outName = path.substr(0, path.length() - 4);
    outName.append("_mono.wav");

    sndfile = sf_open(outName.c_str(), SFM_WRITE, &sfinfo);
    if (sndfile == nullptr) {
        sf_close(sndfile);
        delete[] audioIn;
        delete[] audioOut;
        throw FileNotCreatedException(outName);
    }
    sf_write_float(sndfile, audioOut, frames);
    sf_close(sndfile);
    // free memory
    delete[] audioIn;
    delete[] audioOut;
}