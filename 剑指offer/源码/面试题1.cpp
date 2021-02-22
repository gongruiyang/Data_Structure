#include <iostream>
#include <string.h>

class CMyString
{
    public:
        CMyString(char* pData = nullptr);
        CMyString(const CMyString& str);
        CMyString& operator=(const CMyString& str)
        {
            if(this != &str)
            {
                CMyString tempStr(str);
                char* tempS = tempStr.m_pData;
                tempStr.m_pData = this->m_pData;
                this->m_pData = tempS;
            }
            return *this;
        }
        CMyString& operator=(const CMyString& str)
        {
            // 自己给自己赋值的情况
            if(this == &str)
                return *this;
            // 清空原有数据
            if(this->m_pData != nullptr)
            {
                delete[] this->m_pData;
                this->m_pData = nullptr;
            }
            // 赋值
            this->m_pData = new char[strlen(str.m_pData) + 1];
            strcpy(m_pData, str.m_pData);
            
            return *this;
        }

        ~CMyString(void);
    private:
        char* m_pData;
};

