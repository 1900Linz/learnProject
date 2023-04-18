#pragma once
#include "audioInfoCommon.h"

//reference : https://www.cnblogs.com/ranson7zop/p/7657874.html

using namespace audioInfo;

class headFormatFactory : public headFormatInterface
{
    Q_OBJECT
public:

    //Ĭ�Ϲ���
    headFormatFactory();

    /**
     * @brief ���ݲ����ʡ����ȵȲ��������ļ���ʽͷ
     * @param format Qt��Ƶ��ʽ�࣬�����в����ʡ����ȵ���Ϣ
     * @param dataSize ��Ч�����ֽ���
     */
    headFormatFactory(const fileInfo& format, unsigned int dataSize);

    /**
     * @brief ���ݲ����ʡ����ȵȲ��������ļ���ʽͷ
     * @param sampleRate �����ʣ���16000Hz
     * @param sampleSize �������ȣ���16λ
     * @param channelCount ����������1������
     * @param dataSize ��Ч�����ֽ���
     */
    headFormatFactory(int sampleRate, int sampleSize,
        int channelCount, unsigned int dataSize);

    bool isValid() const override;
};

