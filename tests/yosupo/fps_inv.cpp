#include <bits/stdc++.h>
#include "ModularInteger.cpp"
#include "NTT.cpp"
#include "PolynomialRing.cpp"
#include "PowerSeries.cpp"
#define int long long
using namespace std;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ms(v, x) memset((v), (x), sizeof(v))
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define iopt ios::sync_with_stdio(false); cin.tie(0)
#define untie(p, a, b) decltype(p.first) a = p.first, decltype(p.second) b = p.second
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int power(int x, int p, int MOD) {
    if(p == 0) return 1%MOD;
    if(p == 1) return x%MOD;
    int res = power(x, p/2, MOD);
    res = (long long)res*res%MOD;
    if(p&1) res = (long long)res*x%MOD;
    return res;
}
 
typedef pair<int, int> ii;
typedef long double LD;
typedef vector<int> vi;

#pragma region template

using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
struct PrettyOS {
    ostream& os;
    bool first;
    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

struct Scanner {
    FILE* fp = nullptr;
    char line[1 << 15];
    size_t st = 0, ed = 0;
    void reread() {
        memmove(line, line + st, ed - st);
        ed -= st;
        st = 0;
        ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    }
    bool succ() {
        while (true) {
            if (st == ed) {
                reread();
                if (st == ed) return false;
            }
            while (st != ed && isspace(line[st])) st++;
            if (st != ed) break;
        }
        if (ed - st <= 50) reread();
        return true;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        while (true) {
            succ();
            size_t sz = 1;
            while (st + sz < ed && !isspace(line[st + sz])) sz++;
            ref.append(line + st, sz);
            st += sz;
            if (st != ed) break;
        }
        return true;
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    bool read_single(T& ref) {
        if (!succ()) return false;
        bool neg = false;
        if (line[st] == '-') {
            neg = true;
            st++;
        }
        ref = T(0);
        while (isdigit(line[st])) {
            ref = 10 * ref + (line[st++] - '0');
        }
        if (neg) ref = -ref;
        return true;
    }
    template <class T> bool read_single(V<T>& ref) {
        for (auto& d : ref) {
            if (!read_single(d)) return false;
        }
        return true;
    }
    void read() {}
    template <class H, class... T> void read(H& h, T&... t) {
        bool f = read_single(h);
        assert(f);
        read(t...);
    }
    Scanner(FILE* _fp) : fp(_fp) {}
};

struct Printer {
  public:
    template <bool F = false> void write() {}
    template <bool F = false, class H, class... T>
    void write(const H& h, const T&... t) {
        if (F) write_single(' ');
        write_single(h);
        write<true>(t...);
    }
    template <class... T>
    void writeln(const T&... t) {
        write(t...);
        write_single('\n');
    }

    Printer(FILE* _fp) : fp(_fp) {}
    ~Printer() { flush(); }

  private:
    static constexpr size_t SIZE = 1 << 15;
    FILE* fp;
    char line[SIZE], small[50];
    size_t pos = 0;
    void flush() {
        fwrite(line, 1, pos, fp);
        pos = 0;
    }
    void write_single(const char& val) {
        if (pos == SIZE) flush();
        line[pos++] = val;
    }
    template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
    void write_single(const T& val) {
        for (char c : val) write_single(c);
    }
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void write_single(T val) {
        if (pos > (1 << 15) - 50) flush();
        if (val == 0) {
            write_single('0');
            return;
        }
        if (val < 0) {
            write_single('-');
            val = -val;  // todo min
        }
        size_t len = 0;
        while (val) {
            small[len++] = char('0' + (val % 10));
            val /= 10;
        }
        reverse(small, small + len);
        memcpy(line + pos, small, len);
        pos += len;
    }
    template <class T> void write_single(const V<T>& val) {
        auto n = val.size();
        for (size_t i = 0; i < n; i++) {
            if (i) write_single(' ');
            write_single(val[i]);
        }
    }
};

#pragma endregion

using namespace lib;
using mint = MintNTT;
using poly = math::Polynomial<mint, NTTMultiplication>;

int32_t main(){
    // Scanner sc(stdin);
    // Printer pr(stdout);
    iopt;

    int n;
    cin >> n;

    V<mint> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto c = series::ln(poly(a), n);
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
