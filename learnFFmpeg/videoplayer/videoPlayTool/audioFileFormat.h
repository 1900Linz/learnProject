#pragma once
#include "audioInfoCommon.h"

//reference : https://www.cnblogs.com/ranson7zop/p/7657874.html

using namespace audioInfo;

class wavHead : public headFormat
{
    Q_OBJECT
public:

    //默认构造
    wavHead();

    /**
     * @brief 根据采样率、精度等参数构造wav格式头
     * @param format Qt音频格式类，包含有采样率、精度等信息
     * @param dataSize 有效数据字节数
     */
    wavHead(const fileInfo& format, unsigned int dataSize);

    /**
     * @brief 根据采样率、精度等参数构造wav格式头
     * @param sampleRate 采样率，如16000Hz
     * @param sampleSize 采样精度，如16位
     * @param channelCount 声道数，如1单声道
     * @param dataSize 有效数据字节数
     */
    wavHead(int sampleRate, int sampleSize,
        int channelCount, unsigned int dataSize);

     bool isValid() const override;
};

class mp3Head : public headFormat
{
    Q_OBJECT
public:

    //默认构造
    mp3Head();

    /**
     * @brief 根据采样率、精度等参数构造wav格式头
     * @param format Qt音频格式类，包含有采样率、精度等信息
     * @param dataSize 有效数据字节数
     */
    mp3Head(const fileInfo& format, unsigned int dataSize);

    /**
     * @brief 根据采样率、精度等参数构造wav格式头
     * @param sampleRate 采样率，如16000Hz
     * @param sampleSize 采样精度，如16位
     * @param channelCount 声道数，如1单声道
     * @param dataSize 有效数据字节数
     */
    mp3Head(int sampleRate, int sampleSize,
        int channelCount, unsigned int dataSize);

    bool isValid() const override;
};
