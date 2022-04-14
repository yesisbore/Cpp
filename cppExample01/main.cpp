#include <iostream>

// using으로 네임스페이스 사용하기
// using namespace name1; or name1::func;
// std::cout << 출력할것 <<  출력할것 << ... <<  출력할것;

// 이름 없는 이름 공간을 사용 하면
namespace ReferenceExample{

    // Reference 참조자 : int& anotherA = a; 선언 시 명시가 반드시 필요함, 초기화 후 다른 참조 불가능
    // 함수 인자로 참조자 받기
    void SumFunc(int& ref){
        ref = 3;
    }

    // 배열의 레퍼런스
    int arr[3] = {1, 2, 3};
    int(&ref)[3] = arr;
    void NumAdd()
    {
        int i =0,sum =0,countNum;
        std::cout << "1 ~ 몇까지 더할까요 ?"<< std::endl ;
        std::cin >> countNum;

        while (++i <= countNum){
            sum += i;
        }

        std::cout << sum << std::endl;
    }
    void MakeArr()
    {
        int arrSize;
        std::cout << "array size : "; std::cin >> arrSize;
        int *list = new int[arrSize];
        for (int i = 0; i < arrSize; i++) {
            std::cin >> list[i];
        }
        for (int i = 0; i < arrSize; i++) {
            std::cout << i << "th element of list : " << list[i] << std::endl;
        }
        delete[] list;
    }

    // 구조체
    typedef struct Animal
    {
        char name[30];
        int age;
        int health;
        int food;
        int clean;
    } Animal;

    void CreateAnimal(Animal *animal)
    {
        std::cout << "동물의 이름? "; std::cin >> animal->name;
        std::cout << "동물의 나이? "; std::cin >> animal->age;
        animal->health = 100;
        animal->food = 100;
        animal->clean = 100;
    }

}

namespace opp
{
    // 클래스 정의
    // Date day(2011, 3, 1); 암시적 방법 (implicit)
    // Date day = Date(2012, 3, 1);  명시적 방법 (explicit)
    // Test() = default; // 디폴트 생성자를 정의해라

    class Animal {
    private:
        int food;
        int weight;
    public:

        void set_animal(int _food, int _weight) {
            food = _food;
            weight = _weight;
        }
    };
}
int main() {

    return 0;
}