#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> M;
    vector<int> D;
    vector<string> ans;

    void InputFormat() {
        LINE(T);
        LINES(M, D) % SIZE(T);
    }

    // void OutputFormat() {
    //     LINES(ans) % SIZE(T);
    // }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4",
            "1 1",
            "10 30",
            "10 1",
            "10 1",
        });
        Output({
            "Mid-Autumn Festival hasn’t come yet.",
            "Mid-Autumn Festival has passed.",
            "Today is Mid-Autumn Festival!",
            "Don’t ask me again!"
        });
    }
    
    void gen_day(){
        for(int i=0;i<T;i++){
            int m = rnd.nextInt(1, 12);
            int d = rnd.nextInt(1, days[m]);
            M.push_back(m);
            D.push_back(d);
        }
    }

    void BeforeTestCase(){
        M.clear();
        D.clear();
    }
    
    void TestCases() {
        for(int i=0;i<100;i++){
            CASE(T = rnd.nextInt(1, 1e2), gen_day());
        }
    }
};