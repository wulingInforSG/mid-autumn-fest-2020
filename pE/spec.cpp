#include <tcframe/spec.hpp>
// #include <vector>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec
{
protected:
    int N, M, K, D;
    vector<int> X;
    vector<int> Y;
    vector<int> ans_x;
    vector<int> ans_y;

    void InputFormat()
    {
        LINE(N, M, K, D);
        LINES(X, Y) % SIZE(K);
    }

    void OutputFormat()
    {
        LINES(ans_x, ans_y);
    }

    void GradingConfig()
    {
        TimeLimit(1);
        MemoryLimit(64000);
    }

    /*void Constraints() {
        CONS(1 <= N && N <= 50);
    }*/
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:

    void BeforeTestCase(){
        X.clear();
        Y.clear();
    }

    void gen_arrayX(){
        for(int i=0;i<K;i++){
            X.push_back(rnd.nextInt(1, N));
        }
    }

    void gen_arrayY(){
        for(int i=0;i<K;i++){
            Y.push_back(rnd.nextInt(1, M));
        }
    }

    void TestCases(){
        for (int i = 1; i <= 10; i++)
        {
            CASE(N = rnd.nextInt(1, 300), M = rnd.nextInt(1, 300), K = rnd.nextInt(1, N * M), D = 0, gen_arrayX(), gen_arrayY());
        }
        for(int i=0;i<20;i++){
            CASE(N = rnd.nextInt(1, 300), M = rnd.nextInt(1, 300), K = rnd.nextInt(1, N * M), D = rnd.nextInt(1, 4), gen_arrayX(), gen_arrayY());

        }
        for(int i=0;i<70;i++){
            CASE(N = rnd.nextInt(1, 3000), M = rnd.nextInt(1, 3000), K = rnd.nextInt(1, N * M), D = rnd.nextInt(1, 4), gen_arrayX(), gen_arrayY());
            
        }
    }
    
   
};
