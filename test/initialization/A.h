//
// Created by wpy on 18-6-25.
//

#ifndef SB123456_A_H
#define SB123456_A_H

template<typename T>
class A {
public:
    A<T>():x(npos){
        printf("create A class success.\n");
    };
    static const T npos = static_cast<T>(511);
private:
    T x;
};


#endif //SB123456_A_H
