//
// Created by Teodora Schiau on 28.04.2024.
//

#ifndef OOP_A6_7_916_SCHIAU_TEODORA_WRITEFILE_H
#define OOP_A6_7_916_SCHIAU_TEODORA_WRITEFILE_H
#include "domain.h"
#include "FileRepository.h"
class WriteFile{
protected:
    vector<Movie> elements;
    string filename;
public:
    virtual void WriteData() = 0;
    virtual void openFile() = 0;
    virtual void setData(vector<Movie> elements) = 0;
    virtual ~WriteFile() = default;
};

class HTML:public WriteFile
{
public:
    HTML();
    void WriteData() override;
    void openFile() override;
    void setData(vector<Movie> elements) override;
    ~HTML() override = default;
};

class CSV:public WriteFile
{

public:
    CSV();
    void WriteData() override;
    void openFile() override;
    void setData(vector<Movie> elements) override;
    ~CSV() override = default;
};

#endif //OOP_A6_7_916_SCHIAU_TEODORA_WRITEFILE_H
