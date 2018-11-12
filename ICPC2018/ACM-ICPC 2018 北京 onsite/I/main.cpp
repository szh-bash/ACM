#include <iostream>
#include <cstring>

using namespace std;

#define MAXN    (100010)


class Number {
public:
    int length;
    short *a;

    Number() : length(0) {
        a = new short[MAXN];
        memset(a, 0, sizeof(a));
    }

    Number(const long long &value) : Number() {
        long long _value = value;
        while (true) {
            a[length] = (short) (_value % 10);
            length += 1;
            _value /= 10;
            if (!_value) break;
        }
    }

private:
    void shorten() {
        while (length > 0 && a[length - 1] == 0) length--;
    }

public:
    Number operator+(const Number &x) {
        shorten();
        Number _result;
        _result.length = max(x.length, length);
        int t = 0;
        for (int i = 0; i < _result.length; i++) {
            t = (a[i] + x.a[i] + t);
            _result.a[i] = (short) (t % 10);
//            cout << i << " " << _result.a[i] << endl;
            t /= 10;
        }
        while (t && _result.length < MAXN) {
            _result.a[_result.length] = (short) (t % 10);
            _result.length++;
            t /= 10;
        }
        return _result;
    }

    Number operator-(Number &x) {
        Number _result = clone();
        for (int i = 0; i < _result.length; i++) {
            _result.a[i] = _result.a[i] - x.a[i];
            if (_result.a[i] < 0) {
                _result.a[i] += 10;
                _result.a[i + 1] -= 1;
            }
//            cout << i << " " << _result.a[i] << endl;
        }
        _result.shorten();
        return _result;
    }

    bool operator<(Number &value) {
        return compare(*this, value) < 0;
    }

    Number clone() {
        shorten();
        Number _result;
        _result.length = length;
        for (int i = 0; i < length; i++) {
            _result.a[i] = a[i];
        }
        return _result;
    }


    Number dec() {
        shorten();
        Number _result;
        _result.length = length;
        for (int i = 0; i < length; i++) _result.a[i] = a[i];
        int i = 0;
        while (_result.a[i] == 0) {
            _result.a[i] = 9;
            i += 1;
        }
        _result.a[i] -= 1;
        return _result;
    }

    friend ostream &operator<<(ostream &output, Number &value) {
        value.shorten();
        int length = value.length;
        if (length <= 0) length = 1;
        for (int i = length - 1; i >= 0; i--) {
            output << value.a[i];
        }
        return output;
    }

    void println() {
        shorten();
        int _length = length;
        if (length <= 0) _length = 1;
        for (int i = _length - 1; i >= 0; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    }

    static int compare(Number &x, Number &y) {
        x.shorten();
        y.shorten();
        if (x.length != y.length) {
            if (x.length < y.length) {
                return -1;
            } else {
                return 1;
            }
        } else {
            int _length = x.length;
            for (int i = _length - 1; i >= 0; i--) {
                if (x.a[i] < y.a[i]) {
                    return -1;
                } else if (x.a[i] > y.a[i]) {
                    return 1;
                }
            }
            return 0;
        }
    }
};

int prefix_sum_length(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return (n + 1) / 2 + 1;
}

int anti_psl(int n) {
    int _result = (n - 1) * 2 - 1;
    if (_result < 1) _result = 1;
    return _result;
}

Number prefix_sum(int n) {
    if (n <= 0) return Number(0);
    if (n == 1) return Number(9);
    if (n == 2) return Number(18);
    int _n = prefix_sum_length(n);
    Number _result;
    _result.length = _n;
    _result.a[_n - 1] = 1;
    for (int i = 1; i <= _n - 2; i++) {
        _result.a[i] = 9;
    }
    _result.a[0] = 8;
    if (n & 1) {
        _result.a[_result.length - 2] = 0;
    }
    return _result;
}

char s[MAXN];

void doit() {
    scanf("%s", s);
    Number _n;
    _n.length = (int) strlen(s);
    for (int i = 0; i < _n.length; i++) {
        _n.a[i] = s[_n.length - 1 - i] - '0';
    }

//    _n.println();
    if (_n.length == 1 && _n.a[0] == 1) {
        printf("0\n");
        return;
    }

    _n = _n.dec();
//    _n.println();

    int _apsl = anti_psl(_n.length);
//    cout << _apsl << endl;

    Number _base;
    int _m;

    _base = prefix_sum(_apsl);
    if (_base < _n) {
        Number _pbase = prefix_sum(_apsl + 1);
        if (_pbase < _n) {
            _base = _pbase;
            _m = _apsl + 1;
        } else {
            _m = _apsl;
        }
    } else {
        _base = prefix_sum(_apsl - 1);
        _m = _apsl - 1;
    }

    _m += 1;
//    _n.println();
//    _base.println();


    Number _left_n = _n - _base;
    _left_n = _left_n.dec();

//    _left_n.println();
//    cout << "length : " << _m << endl;

    int _left_length = (_m + 1) / 2;
    Number half;
    half.length = _left_length;
    half.a[_left_length - 1] = 1;
    half = half + _left_n;

    for (int i = half.length - 1; i >= 0; i--) {
        printf("%d", half.a[i]);
    }
    if (_m & 1) {
        for (int i = 1; i < half.length; i++) {
            printf("%d", half.a[i]);
        }
    } else {
        for (int i = 0; i < half.length; i++) {
            printf("%d", half.a[i]);
        }
    }
    printf("\n");

}

int main() {
//    prefix_sum(1).println();
//    prefix_sum(2).println();
//    prefix_sum(3).println();
//    prefix_sum(4).println();
//    prefix_sum(5).println();
//    prefix_sum(6).println();
//    prefix_sum(7).println();
//    prefix_sum(8).println();
//    prefix_sum(9).println();
//    return 0;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) doit();
    return 0;
}