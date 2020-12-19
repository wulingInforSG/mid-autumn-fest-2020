#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N;
    vector<string> name;
    vector<int> money, a, b, c;

    void InputFormat() {
        LINE(N);
        LINES(name, money, a, b, c) % SIZE(N);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

   
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
   

    void BeforeTestCase(){
        name.clear();
        money.clear();
        a.clear();
        b.clear();
        c.clear();
    }

    string shu_string = "abcdefghijklmnopqrstuvwxyz";
    string rnd_str(int m){
        rnd.shuffle(shu_string.begin(), shu_string.end());
        return shu_string.substr(0, m);
    }

    void gen(){
        for(int i=0;i<N;i++){
            name.push_back(rnd_str(rnd.nextInt(1, 19)));
            money.push_back(rnd.nextInt(1, 1e8));
            a.push_back(rnd.nextInt(1, 1000));
            b.push_back(rnd.nextInt(1, 1000));
            c.push_back(rnd.nextInt(1, 1000));
        }
    }

    void TestCases() {
        for(int i=1;i<=100;i++)
            CASE(N = rnd.nextInt(1, 1e5), gen());
    }
};