#ifndef ___714_ONPU__gakuhu__
#define ___714_ONPU__gakuhu__

#include <iostream>
#include "ofMain.h"

#define onpu_sum 30 //楽譜の中の全ての音符の個数の総計

#endif /* defined(___714_ONPU__gakuhu__) */


class Gakuhu{
private:
    
    void setup();//楽譜のセットアップ
    void sound(int i, char a,float b);//楽譜を格納するための命令
    int takasa_alpha[onpu_sum];//高さの文字列を数字に変換する
    void time_exist(float t,int tempo);//楽譜に指定した時間になったら音符を存在しているとみなす。
    void PT_SET(float t);//音符の座標を設定  ＆   画面外の音符の消去（処理軽減のため）
    int onpu_number_alpha=0;
    float s_time[onpu_sum];//i番目の音がプログラムが開始されてから何秒後に鳴るか。
    
    ofImage image[onpu_sum];//音符画像
    
public:
    Gakuhu();//コンストラクタ、setup関数代わり
    void draw();//実際に描画しているところ
    void update(int t,int tempo);//音符の細かい設定〜描画までひと通りやります、tに時間、tempoにテンポ。
    void destroy(int i);//i番目の音符を消します。
    ofVec2f onpu_PT[onpu_sum];//音符の座標、座標は全てここに記録されてます。
    bool onpu_EX[onpu_sum];//音符が表示されてるか否か。trueなら表示。EXはexistanceの略です！
    char takasa[onpu_sum];//i番目の音の高さ
    
    int onpu_number=0;
    
    //※注
    //★★★★★食べているかの判定はonpu_PT[i]との座標の一致にさらに、onpu_EX[i]がtrueになっていることを条件に入れるようお願いします。★★★★★
    
};