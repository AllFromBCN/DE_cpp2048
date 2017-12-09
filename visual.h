//
// Created by 정수민 on 2017. 12. 9..
//

#ifndef VISUAL_H
#define VISUAL_H

//
// Created by 정수민 on 2017. 12. 9..
//
/*
기본사항 : 생성자, 소멸자, 복사생성자, this, 예외처리
const 함수 : map print 시
*/
#include "Map.h"
#include "Score.h"
#include <iostream>
#include <string>

using namespace std;

class Visual{
    int score;
    int size;

public:
    Visual(){}
    ~Visual(){}

    void show();
    Map start();
};
#endif //VISUAL_H
