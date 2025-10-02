#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "json_helper.hpp"

JsonConfig::JsonConfig(std::string filename)
{
    std::ifstream file(filename);
    std::string str;

    Json::Reader reader;

    if (file)
    {
        std::ostringstream ss;
        ss << file.rdbuf();
        str = ss.str();

        // remove line breaks to prepare parsing by Json::Reader
        str.erase(std::remove(str.begin(), str.end(), '\r'), str.cend());
        str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());

        int ret = reader.parse(str.c_str(), mainNode);

        if (!ret)
        {
            printf("parsing node failed ...");
        }
    }
}

JsonConfig::JsonConfig(Json::Value JsonVal)
{
    mainNode = JsonVal;
}

JsonConfig::~JsonConfig()
{

}

int JsonConfig::getValueFromNode(Json::Value node, Json::Value &val)
{
    int ret = -1;

    if (node.isObject() || node.isArray())
    {
        val = node;
        ret = 0;
    }

    return ret;
}

int JsonConfig::getValueFromNode(Json::Value node, int32_t &val)
{
    int ret = -1;

    if (node.isNumeric())
    {
        val = node.asInt();
        ret = 0;
    }

    return ret;
}

int JsonConfig::getValueFromNode(Json::Value node, uint32_t &val)
{
    int ret = -1;

    if (node.isNumeric())
    {
        val = node.asInt();
        ret = 0;
    }

    return ret;
}

int JsonConfig::getValueFromNode(Json::Value node, int64_t &val)
{
    int ret = -1;

    if (node.isNumeric())
    {
        val = node.asInt();
        ret = 0;
    }

    return ret;
}

int JsonConfig::getValueFromNode(Json::Value node, double &val)
{
    int ret = -1;

    if (node.isNumeric())
    {
        val = node.asDouble();
        ret = 0;
    }

    return ret;
}

int JsonConfig::getValueFromNode(Json::Value node, bool &val)
{
    int ret = -1;

    if (node.isBool())
    {
        val = node.asBool();
        ret = 0;
    }

    return ret;
}

int JsonConfig::getValueFromNode(Json::Value node, std::string &val)
{
    int ret = -1;

    if (node.isString())
    {
        val = node.asString();
        ret = 0;
    }

    return ret;
}

