#include "sm.h"
#include <gtest/gtest.h>
#include <chrono>
class Timer {
public:
    std::chrono::high_resolution_clock::time_point startCounting;
    std::chrono::high_resolution_clock::time_point stopCounting;

    void Start() {
		startCounting = std::chrono::high_resolution_clock::now();
	}
    void Stop() {
    stopCounting = std::chrono::high_resolution_clock::now();
	}
    long timeInMS() {
    	return std::chrono::duration_cast<std::chrono::microseconds>(Timer::stopCounting - Timer::startCounting).count();
	}
};
/* pseudo-losowe liczby, do przeprowadzania obliczen dla argumentow o zadanej wielkosci
auto a3 = natural({53878,40934,72980});
auto b3 = natural({52441,16829,48152});

auto a4 = natural({62491,18622,94220,94386});
auto b4 = natural({90505,86608,62648,57716});

auto a5 = natural({49012,94506,24651,77361,76986}); 
auto b5 = natural({3685,97061,35234,18362,20150});

auto a6 = natural({473,4555,59757,99988,69188,69661});
auto b6 = natural({61090,2816,18278,49549,92994,6627});

auto a7 = natural({96204,35156,31503,1738,26496,36117,89922});
auto b7 = natural({94046,42466,34144,46470,50122,61494,14249});

auto a8 = natural({61294,13885,92417,49281,73036,66100,70898,94583});
auto b8 = natural({32316,32702,1401,2748,37882,64427,61031,82846});

auto a9 = natural({58799,55496,88462,87703,20351,5058,31898,88790,77591});
auto b9 = natural({94659,14305,60115,17692,14982,90062,99793,86580,4427});

auto a10 = natural({92256,58023,66345,52383,7385,9612,5711,76792,40877,98620});
auto b10 = natural({38529,91075,51825,14848,54717,67870,41046,50197,98895,76255});

auto a15 = natural({39717,6827,27630,76085,15177,92250,58105,51677,55803,62439,63620,25940,67731,93037,97696});
auto b15 = natural({23096,76280,30120,33129,74415,84372,38182,64711,49588,43676,39663,38858,94313,20080,58246});

auto a20 = natural({82385,46089,27985,67134,74474,92850,25677,60121,55578,4776,29597,79548,85797,19767,12718,20126,
40240,27005,92501,74047});
auto b20 = natural({82776,94856,73604,76878,11913,42282,27149,44949,90667,86146,76830,92721,65773,17017,30780,15160,
83689,41251,85726,21474});

auto a25 = natural({15484,24559,55207,79349,95916,96323,87430,53788,40227,50341,83791,21907,
389,92347,67903,57646,73643,30178,47572,82451,12292,96195,70446,89476,80419});
auto b25 = natural({69358,42535,98035,34181,56673,96450,43341,79280,27358,43191,653,18867,63258,49248,9507,68890,43150,
59948,53687,85593,48168,31806,21756,32511,18696});

auto a30 = natural({2973,41774,10490,54955,60760,56453,45414,10377,21551,98528,87039,2092,98410,3246,14838,23688,48495,97836,
63806,93711,33087,7599,57857,98122,39586,47886,47355,1341,75635,86974});
auto b30 = natural({50890,92380,46642,36,90887,55776,52776,47046,92668,779,69852,46231,67683,55604,78363,45692,29823,19443,
65562,33048,47128,2132,12825,15348,26996,57336,26010,36201,87827,49325});

auto a40 = natural({49631,24774,56671,86118,21754,15750,12598,52431,1767,34460,44411,7940,60021,14620,65283,13865,15793,
82981,1312,95324,86302,53302,46846,3884,47054,86659,13130,98248,21989,75834,2713,85747,78960,69228,30191,669,18010,29671,
3711,83497});
auto b40 = natural({28773,1995,69209,57058,6285,98488,49585,39870,58127,92602,14616,37147,21695,7936,80723,21850,80337,7266,
91401,55597,6372,22431,87388,43355,94538,46758,22866,74712,88337,15088,24301,93658,43568,9049,33475,43341,62976,55163,
72456,52109});

auto a50 = natural({39140,69885,22853,29183,91143,22440,30409,2472,20226,79160,72943,75666,51262,93887,38511,79517,95065,
51943,59522,8929,73551,26300,25298,95371,92814,22896,58850,98742,13075,47235,68232,27595,24197,86640,63422,50673,2197,
18707,45772,99394,72920,20334,3681,22907,74232,26832,99405,15207,84415,99255});
auto b50 = natural({16222,97408,73004,80397,33810,21541,21625,21847,63002,20678,94877,96658,75503,85689,90370,69218,79829,
67587,2013,61476,77836,80617,41767,91992,63808,15845,62966,89700,96602,50428,27689,46129,28753,65106,66760,43120,15396,
8384,66114,62718,58959,43950,1611,41970,63460,40079,26422,26312,5687,98863});

auto a75 = natural({41509,73280,91601,38999,36918,50085,6969,93919,87684,48867,10378,49294,93444,3773,56518,73658,5879,28386,
29947,94820,20977,63194,23729,72939,39145,38051,31515,41945,4550,69131,20899,95358,57711,40301,76229,35900,93209,28755,615,
81102,21186,74175,67623,5970,62898,2665,69703,12608,83034,83908,88824,4194,81667,18160,46280,62673,80879,97917,83603,62745,
90144,5556,22190,1925,67533,48227,70620,72934,16882,33945,8613,92248,7915,15096,88154});
auto b75 = natural({29302,34930,21581,36781,9723,25685,33366,79522,55046,86836,32424,95056,14101,98857,71317,50979,18659,
23642,38432,32134,49290,79390,57208,46421,62305,63235,74397,47407,84479,53672,40259,71296,24430,40665,91250,94758,18172,
78701,38449,65491,39913,75124,55177,85239,58712,92952,49172,53168,85261,57137,46494,24097,3393,56779,84589,1272,86058,
98809,18697,78615,75239,28001,70586,62859,23070,91542,32988,61279,10187,57321,65005,91494,39455,33069,83565});

auto a100 = natural({16147,91582,82321,13186,55093,32049,46803,16117,44104,56564,65986,19306,8845,10390,44807,
49943,28690,55960,89887,73391,8054,91464,42563,23848,70254,46092,97175,3638,31423,49407,80510,
83188,31120,32820,48498,70902,81986,4387,8508,28222,65066,98200,86987,39878,88161,18926,62592,
91714,74637,16939,8908,96648,28529,53693,44237,68399,67494,2505,62057,3729,18849,32246,46555,96627,
25107,35053,68081,12621,3104,35930,88125,67240,43573,81818,20307,15261,59564,84356,34579,1054,
38434,73583,58141,43451,59648,37122,42125,88670,70246,82849,92980,30870,46501,84194,21262,27573,
48191,40788,74227,63903});
auto b100 = natural({1836,70491,98129,34802,38726,40110,18646,18717,53419,35286,55993,13147,88261,30589,27063,
67725,24511,31448,44460,74746,91486,90783,72505,24953,42233,21335,14106,24319,5263,47021,31823,
81138,43892,46703,32623,19715,4982,20563,39928,34051,8241,54372,19553,58699,13525,11608,84329,23570,
49639,43055,5517,48634,11601,67394,92159,92706,58041,96244,48122,40148,98500,94521,69742,24931,
82981,63858,26561,6786,52166,24082,53468,50211,17839,72911,33703,7300,82903,4311,98216,55162,459,
39271,41583,81740,21532,88479,77141,45849,46915,90326,68123,22586,72516,7001,59984,60709,91930,
71141,40301,46041});
*/



//Testy operacji arytmetycznych na Natural
TEST(NaturalAddTest, natAdd1) {
	auto a = natural({ 17,22,11 });
	auto b = natural({ 12,11,10 });
	auto c = natural({ 29,33,21 });
	natural wynik;
	wynik.add(a, b);
	EXPECT_EQ(wynik.getValue(), c.getValue());

};

TEST(NaturalSubTest, natSub1) {
	auto a = natural({ 17,22,11 });
	auto b = natural({ 12,11,10 });
	auto c = natural({ 5,11,1 });
	natural wynik;
	wynik.subtract(a, b);
	EXPECT_EQ(wynik.getValue(), c.getValue());

};
TEST(NaturalDivTest, NaturalDiv1) {
	auto a = natural({ 17,22,11 });
	auto b = natural({ 12,11,10 });
	auto c = natural({ 1 });
	natural wynik;
	wynik.divide(a, b);
	EXPECT_EQ(wynik.getValue(), c.getValue());

};

TEST(NaturalDivTest, NaturalDiv2) {
	auto a = natural({ 520 });
	auto b = natural({ 511 });
	auto c = natural({ 1 });
	natural wynik;
	wynik.divide(a, b);
	EXPECT_EQ(wynik.getValue(), c.getValue());
}


//Testy operacji arytmetycznych na smNum wykorzystujac Natural

//dodawanie znaki +
TEST(smNumAddTest, smNumAdd1) {
	auto a = natural({ 82931, 2136512, 12376 });
	auto b = natural({ 192,62 });
	auto c = natural({ 83123, 2136574, 12376 });
	auto  a1 = smNum( 0,a );
	auto  b1 = smNum( 0,b );
	auto c1 = smNum( 0,c );
	smNum wynik;
	wynik.add(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}
//dodawanie znaki -
TEST(smNumAddTest, smNumAdd2) {
	auto a = natural({ 27623,9152, 9124 });
	auto b = natural({  1192, 1925});
	auto c = natural({ 28815, 11077, 9124});
	auto  a1 = smNum({ 1,a });
	auto  b1 = smNum({ 1,b });
	auto c1 = smNum({ 1,c });
	smNum wynik;
	wynik.add(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}

//dodawanie roznych znakow
TEST(smNumAddTest, smNumAdd3) {
	auto a = natural({ 21367134, 12487124, 12387128 });
	auto b = natural({ 1192, 39713847 });
	auto c = natural({   21365942, 4267740573, 12387127 });
	auto  a1 = smNum({ 0,a });
	auto  b1 = smNum({ 1,b });
	auto c1 = smNum({ 0,c });
	smNum wynik;
	wynik.add(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}

TEST(smNumAddTest, smNumAdd4) {
	auto a = natural({ 1233453,120391,9471393 });
	auto b = natural({ 1192, 1925123 });
	auto c = natural({ 1232261, 4293162564, 9471392 });
	auto  a1 = smNum({ 1,a });
	auto  b1 = smNum({ 0,b });
	auto c1 = smNum({ 1,c });
	smNum wynik;
	wynik.add(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}


//odejmowanie, znaki +
TEST(smNumSubTest, smNumSub1) {
	auto a = natural({ 27623,9152, 9124 });
	auto b = natural({ 1192, 1925 });
	auto c = natural({ 26431, 7227, 9124});
	auto  a1 = smNum({ 0,a });
	auto  b1 = smNum({ 0,b });
	auto c1 = smNum({ 0,c });
	smNum wynik;
	wynik.sub(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}
// znaki -
TEST(smNumSubTest, smNumSub2) {
	auto a = natural({ 92837, 11825, 8291028 });
	auto b = natural({ 1209327, 1238712, 423184, 81236 });
	auto c = natural({ 1116490, 1226887, 4287099452, 81235 });
	auto  a1 = smNum({ 1,a });
	auto  b1 = smNum({ 1,b });
	auto c1 = smNum({ 0,c });
	smNum wynik;
	wynik.sub(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}
//rozne znaki
TEST(smNumSubTest, smNumSub3) {
	auto a = natural({ 152637, 12872136, 935, 1 });
	auto b = natural({ 17829, 8263, 901238 });
	auto c = natural({ 170466, 12880399, 902173, 1});
	auto  a1 = smNum({ 1,a });
	auto  b1 = smNum({ 0,b });
	auto c1 = smNum({ 1,c });
	smNum wynik;
	wynik.sub(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}

TEST(smNumSubTest, smNumSub4) {
	auto a = natural({ 12678, 9351, 82643, 826});
	auto b = natural({ 56373, 8299, 9, 1 });
	auto c = natural({ 69051, 17650, 82652, 827 });
	auto  a1 = smNum({ 0,a });
	auto  b1 = smNum({ 1,b });
	auto c1 = smNum({ 0,c });
	smNum wynik;
	wynik.sub(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}

//testy mnozenia, znaki +

TEST(smNumMulTest, smNumMul1) {
	auto a = natural({ 27623,9152, 9124 });
	auto b = natural({ 1192, 1925 });
	auto c = natural({ 32926616,64083459, 28493408, 17563700 });
	auto  a1 = smNum({ 0,a });
	auto  b1 = smNum({ 0,b });
	auto c1 = smNum({ 0,c });
	smNum wynik;
	wynik.mul(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}

//znaki -
TEST(smNumMulTest, smNumMul2) {
	auto a = natural({ 36192, 129 });
	auto b = natural({ 93, 912647, 92137, 9123 });
	auto c = natural({ 3365856, 2965761149, 3452353774, 342065289, 1176867 });
	auto  a1 = smNum({ 1,a });
	auto  b1 = smNum({ 1,b });
	auto c1 = smNum({ 0,c });
	smNum wynik;
	wynik.mul(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}
//rozne znaki

TEST(smNumMulTest, smNumMul3) {
	auto a = natural({ 217, 81, 9213});
	auto b = natural({ 9 ,71 });
	auto c = natural({ 1953, 16136, 88668, 654123 });
	auto  a1 = smNum({ 1,a });
	auto  b1 = smNum({ 0,b });
	auto c1 = smNum({ 1,c });
	smNum wynik;
	wynik.mul(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}
TEST(smNumMulTest, smNumMul4) {
	auto a = natural({ 2, 1 });
	auto b = natural({ 4000000000, 1 });
	auto c = natural({3705032704 , 4000000003, 1 });
	auto  a1 = smNum({ 0,a });
	auto  b1 = smNum({ 1,b });
	auto c1 = smNum({ 1,c });
	smNum wynik;
	wynik.mul(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());
}
//badanie przeniesienia
TEST(Przeniesienie, przen) {
	auto a = natural({ 4294967293 });
	auto b = natural({ 2  });
	auto c = natural({ 4294967290 , 1});
	natural wynik;
	wynik.multiply(a, b);
	EXPECT_EQ(c.getValue(), wynik.getValue());
}
//testy dzielenia


TEST(smNumDivTest, smDiv1) {
	auto a = natural({ 17 , 562 });
	auto b = natural({ 20000000 });
	auto c = natural({ 120688 });
	auto a1 = smNum({ 0,a });
	auto b1 = smNum({ 0 , b });
	auto c1 = smNum({ 0, c });
	smNum wynik;
	wynik.div(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule() );
	EXPECT_EQ(wynik.getSign(), c1.getSign());

}

TEST(smNumDivTest, smDiv2) {
	auto a = natural({ 127 , 1 });
	auto b = natural({ 3004012 });
	auto c = natural({ 1429 });
	auto a1 = smNum({ 1,a });
	auto b1 = smNum({ 0 , b });
	auto c1 = smNum({ 1, c });
	smNum wynik;
	wynik.div(a1, b1);
	EXPECT_EQ(wynik.getModule(), c1.getModule());
	EXPECT_EQ(wynik.getSign(), c1.getSign());

}

TEST(TestOdejmowania, Odejmowanie) {
	std::vector<uint32_t> vect;
	std::vector<uint32_t> vect2;
	vect.push_back(55);
	vect.push_back(1);
	vect2.push_back(16);
	vect2.push_back(1);
	std::vector<uint32_t> vect3;
	vect3.push_back(39);
	vect3.push_back(0);
	smNum wynik(vect3);
	smNum a1(vect);
	smNum a2(vect2);
	smNum a3;
	a3.sub(a1, a2);
	 EXPECT_EQ(a3.getModule(),wynik.getModule());
		EXPECT_EQ(a3.getSign(), wynik.getSign());
}

TEST(NaturalTest, initWithZero) {
	auto a = natural(0);
	EXPECT_TRUE(a.isZero());
	std::vector<uint32_t> zero;
	zero.push_back(0);
	EXPECT_EQ(a.getValue(), zero);
}

TEST(NaturalTest, initWithVector) {
	auto a = natural({ 1,2,3,4 });
	EXPECT_EQ(a.size(), 4);
}
TEST(NaturalTest, initWithNatural) {
	auto a = natural({ 6,5,4,3 });
	natural b = natural(a);
	EXPECT_TRUE(a == b); //test operatora ==
}

TEST(NaturalTest, decremetZero) {
	std::vector<uint32_t> zero;
	zero.push_back(0);
	auto a = natural(zero);
	EXPECT_THROW(--a, std::runtime_error);
}
TEST(NaturalTest, divideByZero) {
	auto a = natural(0);
	auto b = natural({ 1266,16,7 });
	natural c;
	EXPECT_THROW(c.divide(b, a), std::runtime_error);
}
TEST(NaturalTest, resultIsLessThanZero) {
	auto a = natural({ 2894,1 });
	auto b = natural({ 1666,2 });
	natural c;
	EXPECT_THROW(c.subtract(a, b), std::runtime_error);
}


TEST(SingMagnitudeTest, emptyNumber2) {
	unsigned val = 14;
	std::vector<uint32_t> check;
	auto a = smNum(1, val);
	check.push_back(val);
	EXPECT_TRUE(a.getSign());
	EXPECT_EQ(a.getModule(), check);
}

TEST(SingMagnitudeTest, emptyNumber3) {
	unsigned val = 500;
	auto a = natural(val); //natural o wartosci +500
	std::vector<uint32_t> check;
	auto b = smNum(0, a);
	check.push_back(val);
	EXPECT_FALSE(b.getSign());
	EXPECT_EQ(b.getModule(), check);
}

long Add100();
long Add2Args();

int main(int argc, char* argv[])
{
	// auto a = natural({ 3,125 });
	// auto b = natural(4294967295);
	// natural wynik;
	// wynik.divide(a, b);
	// wynik.print();
	// return 0;
	::testing::InitGoogleTest(&argc, argv);
  	return RUN_ALL_TESTS();
}

long Add2Args(){
	auto a = natural(2455);
	auto b = natural(6512);
	auto a1 = smNum(1,a);
	auto b1 = smNum(0,b);
	smNum result;
	Timer measured;
	measured.Start();
	for(unsigned i=0; i<100; i++)
		result.add(a1,b1);
	measured.Stop();
	return measured.timeInMS();
}
long Sub2Args(){
	auto a = natural(2455);
	auto b = natural(6512);
	auto a1 = smNum(1,a);
	auto b1 = smNum(0,b);
	smNum result;
	Timer measured;
	measured.Start();
	result.sub(a1,b1);
	measured.Stop();
	return measured.timeInMS();
}
long Mul2Args(){
	auto a = natural(2455);
	auto b = natural(6512);
	auto a1 = smNum(0,a);
	auto b1 = smNum(1,b);
	smNum result;
	Timer measured;
	measured.Start();
	result.mul(a1,b1);
	measured.Stop();
	return measured.timeInMS();
}
long Div2Args(){
	auto a = natural(2455);
	auto b = natural(6512);
	auto a1 = smNum(0,a);
	auto b1 = smNum(0,b);
	a1.print();
	b1.print();
	smNum result;
	Timer measured;
	measured.Start();
	result.div(b1,a1);
	measured.Stop();
	return measured.timeInMS();
}

long Add100(){
auto a100 = natural({16147,91582,82321,13186,55093,32049,46803,16117,44104,56564,65986,19306,8845,10390,44807,
49943,28690,55960,89887,73391,8054,91464,42563,23848,70254,46092,97175,3638,31423,49407,80510,
83188,31120,32820,48498,70902,81986,4387,8508,28222,65066,98200,86987,39878,88161,18926,62592,
91714,74637,16939,8908,96648,28529,53693,44237,68399,67494,2505,62057,3729,18849,32246,46555,96627,
25107,35053,68081,12621,3104,35930,88125,67240,43573,81818,20307,15261,59564,84356,34579,1054,
38434,73583,58141,43451,59648,37122,42125,88670,70246,82849,92980,30870,46501,84194,21262,27573,
48191,40788,74227,63903});
auto b100 = natural({1836,70491,98129,34802,38726,40110,18646,18717,53419,35286,55993,13147,88261,30589,27063,
67725,24511,31448,44460,74746,91486,90783,72505,24953,42233,21335,14106,24319,5263,47021,31823,
81138,43892,46703,32623,19715,4982,20563,39928,34051,8241,54372,19553,58699,13525,11608,84329,23570,
49639,43055,5517,48634,11601,67394,92159,92706,58041,96244,48122,40148,98500,94521,69742,24931,
82981,63858,26561,6786,52166,24082,53468,50211,17839,72911,33703,7300,82903,4311,98216,55162,459,
39271,41583,81740,21532,88479,77141,45849,46915,90326,68123,22586,72516,7001,59984,60709,91930,
71141,40301,46041});
smNum a1(0,a100);
smNum b1(1,b100);
	smNum result;
	Timer measured;
	measured.Start();
	result.div(a1,b1);
	measured.Stop();
	return measured.timeInMS();
}