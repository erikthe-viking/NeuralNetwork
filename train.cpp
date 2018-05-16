#include "train.h"
using namespace std;
train::train(){

    vector<double> A{0, 1, 1, 1, 0,1, 0, 0, 0, 1, 1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 1, 1, 1, 1,1, 0, 0, 0, 1, 1, 0, 0, 0, 1};  train::alphabet.push_back(A);
    vector<double> B{1, 1, 1, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 1, 1, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 1, 1, 1, 0};    train::alphabet.push_back(B);
    vector<double> C{0, 1, 1, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 0, 0, 0, 1,0, 1, 1, 1, 0};    train::alphabet.push_back(C);
    vector<double> D{1, 1, 1, 0, 0,1, 0, 0, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 1, 0,1, 1, 1, 0, 0};    train::alphabet.push_back(D);
    vector<double> E{1, 1, 1, 1, 1,1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 1, 1, 1, 0,1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 1, 1, 1, 1};    train::alphabet.push_back(E);
    vector<double> F{1, 1, 1, 1, 1,1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0}; train::alphabet.push_back(F);
    vector<double> G{0, 1, 1, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 0, 0, 1, 1,1, 0, 0, 0, 1,0, 1, 1, 1, 0};    train::alphabet.push_back(G);
    vector<double> H{1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 1, 1, 1, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1};    train::alphabet.push_back(H);
    vector<double> I{0, 1, 1, 1, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0};  train::alphabet.push_back(I);
    vector<double> J{0, 0, 1, 1, 1,0, 0, 0, 1, 0,0, 0, 0, 1, 0,0, 0, 0, 1, 0,0, 0, 0, 1, 0,1, 0, 0, 1, 0,0, 1, 1, 0, 0};    train::alphabet.push_back(J);
    vector<double> K{1, 0, 0, 0, 1,1, 0, 0, 1, 0,1, 0, 1, 0, 0,1, 1, 0, 0, 0,1, 0, 1, 0, 0,1, 0, 0, 1, 0,1, 0, 0, 0, 1};    train::alphabet.push_back(K);
    vector<double> L{1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 0, 0,0, 0,1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 1, 1, 1, 1};     train::alphabet.push_back(L);
    vector<double> M{1, 0, 0, 0, 1,1, 1, 0, 1, 1,1, 0, 1, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1};    train::alphabet.push_back(M);
    vector<double> N{1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 1, 0, 0, 1,1, 0, 1, 0, 1,1, 0, 0, 1, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1};    train::alphabet.push_back(N);
    vector<double> O{0, 1, 1, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,0, 1, 1, 1, 0};    train::alphabet.push_back(O);
    vector<double> P{1, 1, 1, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 1, 1, 1, 0,1, 0, 0, 0, 0,1, 0, 0, 0, 0,1, 0, 0, 0, 0};    train::alphabet.push_back(P);
    vector<double> Q{0, 1, 1, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 1, 0, 1,1, 0, 0, 1, 0,0, 1, 1, 0, 1};    train::alphabet.push_back(Q);
    vector<double> R{1, 1, 1, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 1, 1, 1, 0,1, 0, 1, 0, 0,1, 0, 0, 1, 0,1, 0, 0, 0, 1};    train::alphabet.push_back(R);
    vector<double> S{0, 1, 1, 1, 1,1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0,0, 0, 0, 0, 1,0, 0, 0, 0, 1,1, 1, 1, 1, 0};  train::alphabet.push_back(S);
    vector<double> T{1, 1, 1, 1, 1,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0};    train::alphabet.push_back(T);
    vector<double> U{1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,0, 1, 1, 1, 0};    train::alphabet.push_back(U);
    vector<double> V{1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,0, 1, 0, 1, 0,0, 0, 1, 0, 0};    train::alphabet.push_back(V);
    vector<double> W{1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 0, 0, 1,1, 0, 1, 0, 1, 1, 0, 1, 0, 1,1, 1, 0, 1, 1,1, 0, 0, 0, 1};   train::alphabet.push_back(W);
    vector<double> X{1, 0, 0, 0, 1,1, 0, 0, 0, 1,0, 1, 0, 1, 0,0, 0, 1, 0, 0,0, 1, 0, 1, 0,1, 0, 0, 0, 1,1, 0, 0, 0, 1};    train::alphabet.push_back(X);
    vector<double> Y{1, 0, 0, 0, 1,1, 0, 0, 0, 1,0, 1, 0, 1, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0,0, 0, 1, 0, 0};    train::alphabet.push_back(Y);
    vector<double> Z{1, 1, 1, 1, 1,0, 0, 0, 0, 1,0, 0, 0, 1, 0,0, 0, 1, 0, 0,0, 1, 0, 0, 0,1, 0, 0, 0, 0,1, 1, 1, 1, 1};    train::alphabet.push_back(Z);

    vector<double> AT{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(AT);
    vector<double> BT{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(BT);
    vector<double> CT{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(CT);
    vector<double> DT{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(DT);
    vector<double> ET{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(ET);
    vector<double> FT{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(FT);
    vector<double> GT{0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(GT);
    vector<double> HT{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(HT);
    vector<double> IT{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(IT);
    vector<double> JT{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(JT);
    vector<double> KT{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(KT);
    vector<double> LT{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(LT);
    vector<double> MT{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(MT);
    vector<double> NT{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(NT);
    vector<double> OT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(OT);
    vector<double> PT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(PT);
    vector<double> QT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0}; train::target_list.push_back(QT);
    vector<double> RT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0}; train::target_list.push_back(RT);
    vector<double> ST{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}; train::target_list.push_back(ST);
    vector<double> TT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}; train::target_list.push_back(TT);
    vector<double> UT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}; train::target_list.push_back(UT);
    vector<double> VT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0}; train::target_list.push_back(VT);
    vector<double> WT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}; train::target_list.push_back(WT);
    vector<double> XT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}; train::target_list.push_back(XT);
    vector<double> YT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}; train::target_list.push_back(YT);
    vector<double> ZT{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}; train::target_list.push_back(ZT);

    // e.g., { 3, 2, 1 } 3 inputs, 1 output, 2 nuerons
    vector<unsigned> dimensions;
    // 3 layers and number of nuerons per layer in topology
    train::dimensions.push_back(35); // 35 inputs
    train::dimensions.push_back(35); // 3 layers
    train::dimensions.push_back(26); // 26 outputs

}