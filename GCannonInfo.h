//
//  GCannonInfo.h
//  Giant
//
//  Created by Mac on 13-9-5.
//
//

#ifndef Giant_GCannonInfo_h
#define Giant_GCannonInfo_h

using namespace std;
 struct CannonInfo{
public:
    int cannonID ;             // id              大炮id
    string  name;             //  name            大炮名字
    int harm     ;              //  harm            大炮伤害
    int consume   ;             //  consume         消耗金币数
    int canHarmNum;              //  canHarmNum      最大伤害数量
    int damageRange;             // damageRange     伤害范围
    float killProbability;       // killProbability 必杀机率
    int interval;               // interval        时间间隔
    int speed;                  //speed           炮弹速度


};

#endif
