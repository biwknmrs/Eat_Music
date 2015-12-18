#include "Atarihantei.h"

int Atarihantei::atarihantei(ofVec2f onpu_Point, ofPoint kuti_Point, int i){
    /*
     onpu_Point     音符の座標
     kuti_Point     検出した口の座標
     kuti_open      口があいてるかあいてないかの判定
     rough          当たり判定の緩さ（誤差）
     ans            0なら当たってない1なら当たってる
     */
    
    int ans;
    int rough = 50;
    
        if( (onpu_Point.x-rough<=kuti_Point.x && kuti_Point.x<=onpu_Point.x+rough)
            //音符のx座標-誤差<=口のx座標<=音符のx座標+誤差
            &&
            (onpu_Point.y-rough<=kuti_Point.y && kuti_Point.y<=onpu_Point.y+rough)
            //音符のy座標-誤差<=口のy座標<=音符のy座標+誤差
           ){
            ans=1;//当たった
        }else{
            ans=0;//当たってない

    }
    return ans;
    
};