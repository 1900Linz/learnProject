#include "audioFileFormat.h"

headFormatFactory::headFormatFactory()
{
    memset(this,0,sizeof(headFormatFactory));
}

headFormatFactory::headFormatFactory(const fileInfo& format, unsigned int dataSize)
    :headFormatFactory(format.sampleRate,format.)
{

}

bool headFormatFactory::isValid() const
{
    return false;
}
