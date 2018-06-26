//
// Created by wpy on 18-6-25.
//

#ifndef SB123456_B_H
#define SB123456_B_H


class B {
public:
    explicit B(int x = 0, bool b = true);

    const char* toString() const;

private:
    int x;
    bool b;
};


#endif //SB123456_B_H
