#include <stdio.h>
#include <unistd.h>
#include <string>
#include <vector>

#include <jsoncpp/json/json.h>

class JsonConfig
{
public:
    JsonConfig(std::string filename);
    JsonConfig(Json::Value JsonVal);

    ~JsonConfig();

    template<typename T>
    int getValueFromNode(std::vector<std::string> key, T &val)
    {
        int ret = 0;

        std::vector<std::string>::iterator it = key.begin();

        Json::Value jval = mainNode;

        while (it != key.end())
        {
            jval = jval[*it];

            if (jval.isObject())
            {
                it++;
            }
            else
            {
                ret = getValueFromNode(jval, val);
                break;
            }
        }

        return ret;
    }

    void echo()
    {
        std::cout << mainNode << std::endl;
    }

    int getValueFromNode(Json::Value node, Json::Value &val);
    int getValueFromNode(Json::Value node, int32_t &val);
    int getValueFromNode(Json::Value node, uint32_t &val);
    int getValueFromNode(Json::Value node, int64_t &val);
    int getValueFromNode(Json::Value node, double &val);
    int getValueFromNode(Json::Value node, bool &val);
    int getValueFromNode(Json::Value node, std::string &val);

private:
    Json::Value mainNode;
};
