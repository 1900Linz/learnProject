#pragma once
#include "audioInfoCommon.h"

//reference : https://www.cnblogs.com/ranson7zop/p/7657874.html

using namespace audioInfo;

class wavHead : public headFormat
{
    Q_OBJECT
public:

    //Ĭ�Ϲ���
    wavHead();

    /**
     * @brief ���ݲ����ʡ����ȵȲ�������wav��ʽͷ
     * @param format Qt��Ƶ��ʽ�࣬�����в����ʡ����ȵ���Ϣ
     * @param dataSize ��Ч�����ֽ���
     */
    wavHead(const fileInfo& format, unsigned int dataSize);

    /**
     * @brief ���ݲ����ʡ����ȵȲ�������wav��ʽͷ
     * @param sampleRate �����ʣ���16000Hz
     * @param sampleSize �������ȣ���16λ
     * @param channelCount ����������1������
     * @param dataSize ��Ч�����ֽ���
     */
    wavHead(int sampleRate, int sampleSize,
        int channelCount, unsigned int dataSize);

     bool isValid() const override;
};

class mp3Head : public headFormat
{
    Q_OBJECT
public:

    //Ĭ�Ϲ���
    mp3Head();

    /**
     * @brief ���ݲ����ʡ����ȵȲ�������wav��ʽͷ
     * @param format Qt��Ƶ��ʽ�࣬�����в����ʡ����ȵ���Ϣ
     * @param dataSize ��Ч�����ֽ���
     */
    mp3Head(const fileInfo& format, unsigned int dataSize);

    /**
     * @brief ���ݲ����ʡ����ȵȲ�������wav��ʽͷ
     * @param sampleRate �����ʣ���16000Hz
     * @param sampleSize �������ȣ���16λ
     * @param channelCount ����������1������
     * @param dataSize ��Ч�����ֽ���
     */
    mp3Head(int sampleRate, int sampleSize,
        int channelCount, unsigned int dataSize);

    bool isValid() const override;
};
