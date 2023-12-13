#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int hp = health;
    
    int bandageCnt = 0; //연속으로 밴드 감은 시간
    int monsterTime = attacks[0][0]; //몬스터가 공격하는 시점
    int monsterAttack = attacks[0][1]; //몬스터 공격량
    
    int mCnt = 0; //몬스터 배열 접근
    
    //오름차순으로 정렬되어 있기 때문에 마지막 공격 시점까지
    for(int i = 1; i <= attacks[attacks.size() -1][0]; i++) {
        if(monsterTime == i) { //몬스터가 공격할 차례일 때
            bandageCnt = 0;
            hp -= monsterAttack;
            if(hp <= 0) return -1;//죽으면 리턴
            
            if(mCnt + 1 < attacks.size()) {
                mCnt++;
                monsterTime = attacks[mCnt][0];
                monsterAttack = attacks[mCnt][1];
            }            
        }
        else { // 공격 안해서 붕대 감을 떄
            bandageCnt++;
            hp += bandage[1];
            if(bandageCnt == bandage[0]) { //밴드 연속해서 감으면 추가 회복
                bandageCnt = 0;
                hp += bandage[2];
            }
            if(hp > health) hp = health; //기본 체력보다 넘으면 최대 체력으로 초기화
        }
    }
    
    return hp;
}