#include <iostream>
#include <cstring>

class Marine {
    static int totalMarinNum;

    int hp;
    int coordX,coordY;
    const int defaultDamage;
    bool isDead;
public:
    Marine();
    Marine(int x,int y );
    Marine(int x,int y , int damage);
    ~Marine();

    static void ShowTotalMarine();
    int Attack () const;
    Marine& Damaged(int earnDamage);
    void Move(int x,int y);

    void ShowState() const;
};
int Marine::totalMarinNum =0;

Marine::Marine() :  hp(50), coordX(0), coordY(0), defaultDamage(5), isDead(false) {totalMarinNum++;}

Marine::Marine(int x, int y) :  hp(50), coordX(x), coordY(y), defaultDamage(5), isDead(false) {totalMarinNum++;}

Marine::Marine(int x, int y, int damage): hp(50), coordX(x), coordY(y), defaultDamage(damage), isDead(false) {totalMarinNum++;}

Marine::~Marine() { totalMarinNum--; }

void Marine::ShowTotalMarine() { std::cout << " 현재 마린 수 : " << totalMarinNum << std::endl; }

int Marine::Attack() const { return defaultDamage; }

Marine& Marine::Damaged(int earnDamage)
{
    hp -= earnDamage;
    if(hp <= 0)
    {
        isDead = true;
    }
    return *this;
}

void Marine::Move(int x, int y)
{
    coordX = x;
    coordY = y;
}

void Marine::ShowState() const
{
    std::cout << " *** Marine : " << " *** " << std::endl;
    std::cout << " Location : X (" << coordX << ") Y (" << coordY << ") "<< std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine* marines[100];

    marines[0] = new Marine(2,3,10);
    Marine::ShowTotalMarine();

    marines[1] = new Marine(3,5,10);
    Marine::ShowTotalMarine();


    std::cout << std::endl << "Marine1 이 Marine2를 공격 ! " << std::endl;
    marines[1]->Damaged(marines[0]->Attack()).Damaged(marines[0]->Attack());

    marines[0]->ShowState();
    marines[1]->ShowState();

    delete marines[0];
    delete marines[1];

    return 0;
}
