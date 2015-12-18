#include "gakuhu.h"


void Gakuhu::update(int t,int tempo){
    float time;
    time=float(t)*float(tempo)/60.0;
    time_exist(time,tempo);
    PT_SET(time);
}

void Gakuhu::sound(int i, char a, float b){
    takasa[i] = a;
    s_time[i] = b;
}

Gakuhu::Gakuhu(){
    
    sound(0,'C',1);
    sound(1,'D',2);
    sound(2,'E',3);
    sound(3,'F',4);
    sound(4,'E',5);
    sound(5,'D',6);
    sound(6,'C',7);
    sound(7,'E',9);
    sound(8,'F',10);
    sound(9,'G',11);
    sound(10,'A',12);
    sound(11,'G',13);
    sound(12,'F',14);
    sound(13,'E',15);
    sound(14,'C',17);
    sound(15,'C',19);
    sound(16,'C',21);
    sound(17,'C',23);
    sound(18,'C',25);
    sound(19,'C',25.5);
    sound(20,'D',26);
    sound(21,'D',26.5);
    sound(22,'E',27);
    sound(23,'E',27.5);
    sound(24,'F',28);
    sound(25,'F',28.5);
    sound(26,'E',29);
    sound(27,'D',30);
    sound(28,'C',31);
    
    for (int i=0;i<onpu_sum;i++){
        
        onpu_EX[i]=false;//一旦全ての音符を非表示に
        
        //takasa_alphaにgakuhuクラスのtakasaに応じた音符のy座標の基準値を計算＆画像読み込み
        switch (takasa[i]) {
            case  'C':
                takasa_alpha[i]=500;
                image[i].loadImage("image/C.png");
                break;
            case  'D':
                takasa_alpha[i]=400;
                image[i].loadImage("image/D.png");
                break;
            case  'E':
                takasa_alpha[i]=300;
                image[i].loadImage("image/E.png");
                break;
            case  'F':
                takasa_alpha[i]=200;
                image[i].loadImage("image/F.png");
                break;
            case  'G':
                takasa_alpha[i]=100;
                image[i].loadImage("image/G.png");
                break;
            case  'A':
                takasa_alpha[i]=0;
                image[i].loadImage("image/A.png");
                break;
        }
    }
    
}
void Gakuhu::time_exist(float t,int tempo){
    if(t>=s_time[onpu_number]*60){
        onpu_EX[onpu_number]=true;
        onpu_number++;
        if(onpu_number==onpu_sum && t>=s_time[onpu_sum-1]) onpu_number=onpu_sum-1;
    }
}

void Gakuhu::PT_SET(float t){
    for (int i=onpu_number_alpha;   i<=onpu_number;     i++){
        onpu_PT[i].set(  ofGetWindowWidth()-5*(t-60*s_time[i])   ,   takasa_alpha[i]+10*sin(t/10)    );
        //楽譜を加速しながら移動、かつ、縦方向はsinで揺らす。
        if(onpu_PT[i].x<-150) onpu_EX[onpu_number]=false;
        //座標外に表示された段階で音符は存在しないとみなす。
    }
}

void Gakuhu::draw(){
    for(int i=0;i<6;i++){
        ofSetColor(0, 0, 255);
        ofLine(0, 100+i*100, 1024, 100+i*100);
        ofSetColor(255, 255, 255);
    }
    for(int i=onpu_number_alpha;i<=onpu_number;i++){
        if(onpu_EX[i]==1) image[i].draw(onpu_PT[i]);
    }
}

void Gakuhu::destroy(int i){
    onpu_EX[i]=0;
}


