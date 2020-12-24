
/*
*        *O*O*O* Cemu0 _____ Cemu0 _____ Cemu0 _____ Cemu0 _____ Cemu0 _____ Cemu0 *O*O*O*
*
*                                       C++ art work Seqence by Cemu0
*                                    art words from https://ascii.co.uk/art
*                                      
*                                       Created at: 16/12/2020
*/

#include <string>

//note only work on Visual studio code
//#define PLAY_SOUND 
//the file has to be in the same folder with the excute file
#define SONG_NAME "mc.wav"

using namespace std;

void Decompress(const string& compressed, string& original)
{
    size_t i = 0;
    size_t repeat;
    size_t l = compressed.length();
    while (i < l)
    {
        // normal alpha charachers
        while (!isdigit(compressed[i]) && i < compressed.length())
            original.push_back(compressed[i++]);

        // repeat number
        repeat = 0;
        while (isdigit(compressed[i]))
            repeat = 10 * repeat + ((size_t)compressed[i++] - '0');

        // unroll releat charachters
        auto char_to_unroll = compressed[i++];
        while (repeat--)
            original.push_back(char_to_unroll);
    }
}

struct IMG
{
    // still const ram anyway ... 
    const int width,height;
    const string &img = "";
    //when u need gif :) but u just not need
    const string &img1 = "";
    //relative
    //const int timechange = 100;
};

const IMG MC = { 106 , 6 ,
    "2 2_2 2_ 6_ 5_2 7_5 2_3 5_ _4 _ 5_2 5_2 5_ 7_ 2_2 2_11 5_ \n"
    " |2 \\/2 |2 4_|2 2_ \\|2 2_ \\ \\3 / /2 / 4_| |2 | |2 2_ \\|_3 _|/ 4_|2_3 2_|2 \\/2 |3 /\\4 / 4_| \n"
    " | \\2 / | |2_2 | |2_) | |2_) \\ \\_/ /2 | |4 | |2_| | |2_) | | | | (3_4 | |2 | \\2 / |2 /2 \\2 | (3_2 \n"
    " | |\\/| |2 2_| |2 _2 /|2 _2 / \\3 /3 | |4 |2 2_2 |2 _2 /2 | |2 \\3_ \\3 | |2 | |\\/| | / /\\ \\2 \\3_ \\ \n"
    " | |2 | | |4_| | \\ \\| | \\ \\2 | |4 | |4_| |2 | | | \\ \\ _| |_ 4_) |2 | |2 | |2 | |/ 4_ \\ 4_) | \n"
    " |_|2 |_|6_|_|2 \\_\\_|2 \\_\\ |_|5 \\5_|_|_ |_|_| _\\_\\5_|5_/3 |_|2 |_|2 |_/_/4 \\_\\5_/ "
};

const IMG TWTW = { 27 , 6 ,
    "4 3_3 3_ 3_3 3_2  \n"
    "3 |2_ \\ / _ \\2_ \\ / _ \\  \n"
    "6 ) | | | | ) | | | |  \n"
    "5 / /| | | |/ /| | | |  \n"
    "4 / /_| |_| / /_| |_| |  \n"
    "3 |4_|\\3_/4_|\\3_/  "
};

const IMG HPNY = { 67 , 4 ,
"3 _ _3 _3 3_ 3_ 2_ 2_2 _2 _2 3_2 _ _ _2 2_ 5_3 _3 3_2  \n"
    "2 | U | / \\ | o \\ o 2\\ V / | \\| 2| 2_2| | | | \\ V / 2_| / \\ | o \\  \n"
    "2 |3 2| o 2|2 _/2 _/ \\ /2 | 2\\ 2| _| | V V |2 \\ /| _| | o 2|3 /  \n"
    "2 |_n_2|_n_2|_| |_|3 |_|2 |_|\\_2|3_| \\_n_/3 |_2|3_2|_n_2|_|2\\  "
};

const IMG TWTW1 = { 24 , 6 ,
    "4 3_3 3_ 3_2 2_ \n"
    "3 |2_ \\ / _ \\2_ \\/_ | \n"
    "6 ) | | | | ) 2| | \n"
    "5 / /| | | |/ / | | \n"
    "4 / /_| |_| / /_ | | \n"
    "3 |4_|\\3_/4_2|_| "
};

const IMG COVID = { 103 , 12 ,
"8 _3._7 .-3'-.52 2_12 .4-.3 \n"
"5 .-'_3._2'.3 '3 _4 \\22 7_16 3.-'2 |`.7 .3 _3 \\2 \n"
"3 .' .'6 '.\\/3 /` '.3 \\.4-.5 .4-2.2-.\\2 3_ `'.13 |6 |2 |5 /2 .' )3 | \n"
"2 / .'10 .3 |5 \\2 ' \\4 \\3 /4 / |2_| ' |2-.\\2 \\12 4.3 |2 |4 |3 (_.4 / \n"
" . '12 |3 '6 |2 ' '3 '. /'3 /2 .2-. | |4 \\2 '13 -|3 |2 |5 \\5 ,2 /2 \n"
" | |12 \\4 \\5 / /2 |4 |'4 /3 |2 | | |5 |2 '13 |3 |2 |6 `'-'/2 /3 \n"
" | |13 `.3 ` 2.' /3 |4 2|4 |3 |2 | | |5 |2 |10 3.'3 `2-'2 .-.4 /2 /4 \n"
" . '16 '-3.-'`4 '.3 `'3 .'3 |2 | | |5 ' .'10 |9 |`.\\2 '2-'2 /5 \n"
"2 \\ '.10 .16 \\8 /4 |2 | | |3_.' /'11 ` 8-\\ | '-4.-'6 \n"
"3 '. `.5_.-'/17 \\6 /5 |2_|/7_.'/13 `9-'16 \n"
"5 `-.6_ /19 '4-'10 \\7_|/41 \n"
"14 `87 "
};

const IMG GLOBE = { 41 , 14 ,
"13 3_5.3_\n"
"9 ,2.-.=2-.-.7 .\n"
"7 .{_2.8 `8 ,. .\n"
"5 .'5 \\6 /8 | ,'.\\`.\n"
"4 /8 :3 ;'10 `4_> \\\n"
"3 :9 `. (11 /7 :\n"
"3 |11 `>\\_9 \\6 r|\n"
"15 /3 \\9 `._3 \\\n"
"3 |10 |6 `10 ;3 |\n"
"4 :10 \\5 /10 `3 ;\n"
"5 \\10 \\.2 '12 ` /\n"
"7 `.8 | /13 .'\n"
"10 `6 `/10 . '\n"
"13 `3-'5.3-2'\n"
};

const IMG HAND = { 37,15,
"12 11_4 4_\n"
"6 6_/3 \\2_2/3 \\2_/4_\\\n"
"4 _/3 \\_/2 :11 2/4_2\\\n"
"3 /|6 :2 :2 2.6 /8 \\\n"
"2 | |5 2:5 2:6 \\8 /\n"
"2 | |5 :|5 2|5 \\ \\6_/\n"
"2 | |5 2|5 2|6 |\\2 /2 |\n"
"3 \\|5 2|5 2|6 |3 / | \\\n"
"4 |5 2|5 2|6 |2 / /_\\ \\\n"
"4 | 3_ 2| 3_ 2|6 | /2 /4 \\\n"
"5 \\_-_/2 \\_-_/ | 4_ |/2_/6 \\\n"
"18 _\\_2-_/4 \\6 /\n"
"17 /4_13 /\n"
"16 /5 \\11 /\n"
"16 \\6_\\9_/"
};

const IMG MOTOR = { 83,33,
"32 :b48 \n"
"20 .'\\10 2$48 \n"
"19 /3 ;9 :P48 \n"
"18 /3 ,;9 ;`48 \n"
"17 /_.-\" L8 _:_48 \n"
"16 :\"6 \\6 ;2 .j-.45 \n"
"16 ;3 _4 ; .2-/ : ;-.()44 \n"
"15 :2 .' \"-./.'.-'2 ;2 2\"4 2_2._37 \n"
"15 './ 2_2.-`.-\"-._/6\"2-:._3 \"-.34 \n"
"13 _.-4\"-._20 \"-.3 \\33 \n"
"10 .-\"2 2_2.4-2\"t3\"4-2._10 \\3 \\13 3_3.+6-.5 \n"
"8 .'2_.-\"_2.2-2\"-.2_2j-. (+)\\2 `.9 ;3 ;9 .-\"4 .-\"5 /;4 \n"
"8 2\"3 2\"9 j /2 ;4 .^\"7 .-\"2 .' \"7-\"7 \\2_2.2-j._5 \n"
"23 / i3 :_.-\"3 _2.2-2\"3 .'17 .-\" /3\\/2 \\;4 \n"
"22 / /2;2 ;(6 3_3.-+-\"16 .-\"3 /o.-\" .-t\\4 \n"
"21 / / :;2 '._2L.+\"\\4 `.o`3._10 .-\"4 .'2\" .-\"3 \"4 \n"
"19 /`-:3 2;3 ;3 ;2 \\4 :`. `. 4\"4-2\"-.3_.'\\ .-\"11 \n"
"10 _6._/3 /3 2:3 :`-':3 \\4 \\ `. `. 4=5 .-j\\ .+t3._10 \n"
"7 .-\"7 /3 /5 ;4 ;2 :-.2 \\2 .'`. `. `.3=2 .-\".'.-\"7 \"-.7 \n"
"5 .'5 _3./3 /`.4 :4 :2 ;2 \\2 `:_2._`2-`. `3-' .'.'3 _3._5 `2.-.2 \n"
"4 /4 .-\"3 /3 /3 \\9 ; ;3 L.+\" 2. `,2 :5 .'.'2 .-\"5 \"-. .-\"\\2 \\ \n"
"3 :4 /5 /3 /\\4 ;7 ,:_;.-\"2 : (2 ) ;3 )2 .'.'-._/9 .-t3 .2-.;\n"
"3 ;3 :3 .-/3 /2 ;3 :7 :2 \\`._2 '. 2\" .'2 : .'.'-._2 \"-._.4-\"3 t-\" :2 '\n"
"2 :3 :3 ; /3 i4 ;3 ;7 \\_ `. 8\" `. ;'.;2 :2 \"+._2 \"-:_2 .-\" ;3 ;2 \n"
"2 ;3 ;3 ;/3 /:4 :3 :8 `., 6\";2.2_.'.',^2-;3 ;2 \"+._o \"^.3 :3 :2 \n"
"2 :3 :3 '\\_.'.'4 ;3 ;10 \"-:4_/3.3_\"2-^-+-:3 :3 '. \"-._;3 ;3 ;2 \n"
"3 ;3 :4 3\"5 ;3 :25 5\"'2 ;3 :4 3\"5 ;3 :3 \n"
"3 :4 \\10 /4 ;33 :4 \\10 /4 ;3 \n"
"4 \\4 \"-.4_.-\"4 /35 \\4 \"-.4_.-\"4 /4 \n"
"5 `.14 .'37 `.14 .'5 \n"
"7 \"-._6 _.-\"41 \"-._6 _.-\"7 \n"
"11 6\"49 6\"2 \n"
};

const IMG VILLAGE ={91,24,
"10 .13 /\"\\2 .11 .\n"
"3 (6 /\"\\11 /~\"~\\/\"\\9 /\"\\4 4_ 2_4 \n"
"4 ) /\\ /\"^\"\\10 /\"~\"\\~\"~\\2 (4 /\"^\"\\2 /\\_\\_\\2|11 )\n"
"3 ()/2_\\/~\"~9_[]_~\"~\"\\~\"\\2 _)3 /~\"~\\ /_\\_\\_2\\|10 (_\n"
"3 |/|2_|\\\"~|4 THE5 | 7_|_|6_~\"/\\_\\_\\_\\_\\10 |Z|\n"
"3 / |2_| \\\"| RED ~ SLED 2| 3_8 3_ |/_\\_\\_\\_\\_2\\ 8_|Z|_6 .\n"
"2 /8_\\|12=3|) (|6 |) (3| .-.2 .-. 2|.2-2.2-2.2-.|4 /\"\\\n"
"2 | 2_2 2_ 2|12 3|\\_/|6 |\\_/3| |_|2 |_| 3|2%2|2%2|2%2| . /\"~\"\\2 *\n"
"2 2|2_2|2_3|.-. {}{} .-.2|5= .2;, 5=2|10=3|2_2|2_2|2_2|/\"\\/~\"~\\ /o\\2 .\n"
"2 2|2_2|2_4|#|2 /\\2 |#3| 3_ 2;{}2; 3_ 2| .-.2 .-. 2|.2-2.2-2.2-.|\"~\"\\\"~\"~/\"o\"\\/\"\\\n"
"2 | 2_2 2_ 3|_|6 |_4|) (| <><> |) (3| |#|2 |#| 3|2%2|2%2|2%2|~\"~\\~\"~\"/o\"o\\\"~\"\\\n"
"2 2|2_2|2_3|.-. {}{} .-.3|\\_/|2 /\\2 |\\_/3| |_|2 |_| 3|2_2|2_2|2_2|\"~\"~\\\"~/o\"o\"o\\\"~\\\n"
"2 2|2_2|2_4|#|2 /\\2 |#|_!_4=6 5=2|10=_!_o^~o^~o~^o~|~_!_\"\\\"/\"o\"o\"\\~\"~_!_\n"
"2 |8=3|_|6 |_|\\O/15=2|GOLDSMITHS\\O/~^o~^o~^o~^|\"\\O/\"~/\"o\"o\"o\"\\\"~\\O/\n"
"2 |3 <>3 2|3=6_2=._|_.13_ 2|3 FINE2 ._|_.9-.|._|_.\"/o\"o\"o\"o\\~._|_.\n"
"2 |2 GIFT2 2| (/6_)_ 2|/5 PI2ZA4 \\2| JEWELRY2 3|APOTHECARY2|~\"|\"~/.\"o\"o\"o\".\\_-| \n"
"2 | SHO2PE 2|(_/\\3_/\\2_ 2|16U2|~^o~2o~o^~2|'10-'|- |_- |7z|3 |\n"
"2 |.2-. .-.|% .4-. .2-.2|.4-2.2-2.4-.%|.-2.2-2.-.2|.2-2.2-2.2-.|_-|3 /7\"\\_ -|\n"
"2 2|[]| | |3%|TOYS| |/\\4|4~2|<>2|4~3%|_2|[]2|_4|2^2|<>2|2^2|2 |_ -|7^|_ -|\n"
"2 2| ;| |_5%4_| |- 4|4_2| ;2|3_5%_2| o2|_4|2_2|; 2|2_2| -|_- /7_\\3 |\n"
"2 2|2_|2_7%5_|2_3|6_|2_|3_7%_|2_|3_2|4_|2_|4_|_[#]_/9_\\_[#]\n"
"2 ~`2 `\"9%~\"^\"`2 `~|~\"^\"~\"`2 `~\"9%`2 `~\"^~|~\"^~`2 `~\"^~\"^\"~\"^11 ~\"~/\n"
"2 lc21_[#]27_[#]30_/\n"
"2 ^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^\"~\"^~"
};

const IMG EXPLOSION = { 79,24,
"31 16_\n"
"26 4_/ (2 (4 )3 )2 \\3_\n"
"25 /( (2 (2 )3 _4 2)2 )3 )\\\n"
"23 2(5 (3 )(4 )2 )3 (3 )2 )\n"
"21 2(/2 ( _(3 )3 (3 _) ) (2 () )2 )\n"
"20 ( (2 ( (_)3 2(4 (3 )2 .2(_ ) .2 )_\n"
"19 ( (2 )4 (6 (2 )4 )3 ) . ) (3 )\n"
"18 (2 (3 (2 (3 ) (2 _2 ( _) ).2 ) . ) ) ( )\n"
"18 ( (2 (3 ) (2 )3 (2 2)5 ) _)(3 )2 )2 )\n"
"17 ( (2 ( \\ ) (4 (_2 ( ) ( )2 )3 ) )2 2) ( )\n"
"18 (2 (3 (2 (3 (_ ( ) ( _4 )2 ) (2 )2 )3 )\n"
"17 ( (2 ( (2 (2 )5 (_2 )2 ) )2 _)3 ) _( ( )\n"
"18 2(2 (3 )(4 (5 _4 )3 _) _(_ (2 (_ )\n"
"19 (_2(2_(_(2_2( ( ( |2 ) ) ) )_2)2_2)_)3_)\n"
"19 2(2_)8 2\\2|3l|l2|3/10 \\_2)\n"
"28 (3 /(/ (2 )2 ) )\\3 )\n"
"26 (4 ( ( ( | | ) ) )\\3 )\n"
"27 (3 /(| / ( 2) ) ) 2) )\n"
"25 (5 ( 4(_(|)_5)5 )\n"
"26 (6 2|\\(|(|)|/2|5 )\n"
"24 (8 |(2|(2|)4|8 )\n"
"26 (5 2/|/l3|)|2\\ \\5 )\n"
"24 (/ / 2/2 /|2/4|2\\2 \\ \\2 \\ _)\n"
"79-"
};

const IMG DYNAMITE = { 68,7,
"60 c5=e\n"
"63 H\n"
"6 12_41 _2,_H2_\n"
"5 (2_2(2_2(3_()39 2/|5 |\n"
"4 (2_2(2_2(3_()()37_2/ |A TNT|\n"
"3 (2_2(2_2(3_()()()36-'2 |5_|\n"
};

const IMG SANTA_FACE = { 46,32,
"8 _\n"
"7 ' `\n"
"6 ,`-'3 2_\n"
"5 (4 ,-\"2 \"3-, _4 ,'\n"
"6 `2-\"|2 ,' ,-\" ' )2-' /7 \n"
"10 | /2 2/\",-\",-._,'.\"2- . _\n"
"10 `/ .2-=\"_.'2 /11 `.\n"
"11 ; /`3\"2 `-'14 `\n"
"11 \\( ,23 `\n"
"12 2`-\\23 '\n"
"11 ,\"2 (21 ,' \n"
"9 ,'5 `2._12 2_,-\"\\-,\n"
"8 '12 `-.-._,._,'2_3. `,-.\n"
"6 ,'14 . 2_5 \\ ,-. \\-:2 \\\n"
"5 ,11 2_ _/-\"2 \\,2-2\"\\ \\_\\ \\_\\_/\n"
"4 ,9 ,-\"2 /6 '2 _.2-\\_3.\"3 \\\n"
"13 ,4 {3 _,-\" -\"13 |\n"
"4 `8 `5 `-\"16 2_2.`-.\n"
"5 \\8 \\4 ,-\"9 2_2.-2\"7 .\n"
"6 `-._6 2\"7 2_,2-\"9 2_3.'\n"
"10 \\8 _,2-\"8 2_2.2-2\"3 /\n"
"11 : _2.-2\"6 2_.,-'\"7 _.-'\n"
"9 ,-2\"6 _.,-2\"12 ,'\n"
"8 ;5 _.-2\"16 ,'\n"
"8 | _.-\"19 ,\"\n"
"8 `'3._18 /\n"
"14 `10 _5 /\n"
"15 `.3_3.-; `\"-./\n"
"16 |5 ' |4 '\n"
"16 |5 ' |4 I2_\n"
"14 ,=2 .-._| |_|`.2_.'2 \n"
"14 `2-\""
};

const IMG SANTA_MERRYCHRISTMAS = { 63,33,
"62W\n"
"2W9 3_ 2_5 4_6 3_4 3_3 _3 _10 2W\n"
"2W8 |3 V2 \\3 / _2 )4 / 2_|2 / 2_| | | | |9 2W\n"
"2W8 | /\\ /\\ | ( (/ /_3 | /4 | /4 \\ \\_| |9 2W\n"
"2W8 |_2|_2|_|2 \\5_|2 |_|4 |_|5 \\2_2 |9 2W\n"
"2W46 | |9 2W\n"
"2W26 _.-3\"-.10 _/ /10 2W\n"
"2W24 _/7_ `.7 |2_/11 2W\n"
"2W23 / 7_ \\2 \\21 2W\n"
"2W23 \\/,-. ,-.\\/3 \\20 2W\n"
"2W23 ()>=3 =<()`._ \\_18 2W\n"
"2W21 ,-(.2-(_)2-.)`-.`(_)17 2W\n"
"2W19 ,'2 /.-'\\_/`-.\\3 `.19 2W\n"
"2W18 /3 /4 `-'4 \\4 \\18 2W\n"
"2W16 ,'4 \\11 /5 `.16 2W\n"
"2W15 /5 _ `.7 ,'2 _5 \\15 2W\n"
"2W14 /5 _/3 `-._.-'4 \\_5 \\14 2W\n"
"2W13 /7_|5 -|O6 |7_\\13 2W\n"
"2W12 {8_}6_|7_{8_}12 2W\n"
"2W12 ,'3 _ \\(5_[|_=]6_)2 / _3 `.10 2W\n"
"2W11 /4 / `'20-`' \\4 \\9 2W\n"
"2W11 `3-'2 |21_|3 `3-'9 2W\n"
"2W20 |5_|5_|5_|19 2W\n"
"2W20 |2_|5_|5_|2_|19 2W\n"
"2W8 _11 |5_|5_|5_|2 3 14 2W\n"
"2W7 | |11 _36 2W\n"
"2W7 | |10 (_)8 _26 2W\n"
"2W2 3_2 | |2_4 3_2 _3 3_2 | |_2 3_2 _4 4_3 3_2 2W\n"
"2W /2 _| |2 _ \\2 / 2_2| | / 2_| |2 _2|3 V2 \\2 / _2 | / 2_| 2W\n"
"2W(2 (_2 | | \\ 2| /3 | | \\2_ \\ | |2 | /\\ /\\ |( (_| | \\2_ \\ 2W\n"
"2W \\3_| |_| |_2|_|3 |_| |3_/ |_|2 |_2|_2|_| \\4_| |3_/ 2W\n"
"2W58 2W\n"
"62W"
};

const IMG CHRISTMAS_TREE_00 = { 45,25,
"18 .!,12 .!,\n"
"17 ~ 6 ~10 ~ 6 ~\n"
"12 .4 ' i `2 .-^-.3 ' i `\n"
"10 _.|,_3 | |2 / .-. \\3 | |\n"
"11 '|`3 .|_|.| (-` ) | .|_|.\n"
"11 / \\ 3_)_(_|2_`-'2_|2_)_(6_\n"
"10 /`,o\\)23_o_(\n"
"9 /_* ~_\\[3_]3_[3_]3_[3_[_[\\`-.\n"
"9 / o .'\\[_]3_[3_]3_[3_]_[3_)`-)\n"
"8 /_,~' *_\\_]17 [_[(2 (\n"
"8 /`. *2 *\\_]17 [3_\\ _\\\n"
"7 /3 `~. o \\]6 ;( ( ;5 [_[_]`-'\n"
"6 /_ *4 `~,_\\4 2( )( ;(;4 [3_]\n"
"6 /3 o2 *2 ~'\\3 /\\ /\\ /\\ /\\3 [_[_]\n" 
"5 / *4 .2~'2 o\\2 2|_2|_2|_2|3 [3_]\n"
"4 /_,.2~'`4 *2 _\\_2|_2|_2|_2|3_[_[_]_\n"
"4 /`~2.2 o8 \\21:\\\n"
"3 / *3 `'~2.3 *3 \\21:\\\n"
"2 /_5 o4 2`2~.2,_\\9=\\_/9='\n"
"2 /2 *6 *5 2.~'\\9 _|_ .-_2-.\n"
" /*4 o3 _2.2~`'*3 o\\11 ( (_)2 )\n"
" `-.2_.~'`'3 *3 3_.-'12 `4-'\n"
"7 \":7-:\"\n"
"9 \\5_/\n"
};

const IMG CHRISTMAS_TREE_01 = { 10,6,
"4 ~*~\n"
"4 /@\\\n"
"3 /%;@\\\n"
"2 o/@,%\\o\n"
"2 /%;`@,\\ \n"
" '3^H3^'"
};

const IMG CHRISTMAS_TREE_02 = { 10,6,
"5 .\n"
"4 ~*~\n"
"3 i/,\\i\n"
"2 i/`,'\\i\n"
" i/`',`'\\i\n"
" '3^M3^`"
};

const IMG CHRISTMAS_TREE_03 = { 10,8,
"5 !\n"
"3 -~*~-\n"
"4 /!\\\n"
"3 /%;@\\\n"
"2 o/@,%\\o\n"
"2 /%;`@,\\\n"
" o/@'%',\\o\n"
" '3^N3^`"
};

const IMG CHRISTMAS_TREE_04 = { 16,13,
"8 .|,\n"
"8 -*-\n"
"7 '/'\\`\n"
"7 /`'o\\\n"
"6 /#,o'`\\\n"
"5 o/`\"#,`\\o\n"
"5 /`o2`\"#,\\\n"
"4 o/#,`'o'`\\o\n"
"4 /o`\"#,`',o\\\n"
"3 o`-._`\"#_.-'o\n"
"7 _|\"|_\n"
"7 \\=%=/3 \n"
"8 3\""
};

const IMG MASK = { 101,38,
"27 5O68 \n"
"24 3O4 O68 \n"
"20 5O5 O69 \n"
"17 3O9 O70 \n"
"12 14O2 O71 \n"
"7 16O18M9O36 10O4 \n"
"6 17O20M7G7M7O2 5O10 5O10 2O2 \n"
"4 11O51MG2MGO5 6O15 2O \n"
"3 3O5M9G2CL5C7G13M3OM2OM5O5MG4M7O21 O \n"
"3 O4MG8M2G3C13L4C5G16MGM3GC4M3O25 2O\n"
"2 O8MG5MG4CL41CLG3MO28 2O\n"
"2 O6M3G4M2G13C18G5C10LfGO2MO28 2O\n"
" O7M4G2M2G9C17G15C6Lf4MO28 2O\n"
" O7M7G7C19G16CL2C4L4M29 2O\n"
" O6M8G6C14G26CLCL3MO29 M \n"
"O10M.2M21G10C2L2CLC2L11CL3MO28 2O \n"
"O4MG2CL12f28LCL12CL3MO27 2O2 \n"
"O3MG2CL5fLf2t18|9t8f7L4CL4M25 3O3 \n"
"O5M4G3C2GCL13f35LGO2MO23 2O5 \n"
" 5M7GMGCL2f8L7CG2C2GC6GC17G2C3MO21 2O7 \n"
" O4M7GMGC6L4C39GC4M19 3O8 \n"
" O5M6G2MC3L4C42GCG3MO16 3O10 \n"
"2 O5M6GMGCL3C33G4C8GC4M14 3O12 \n"
"3 O6GM3G2MG4C20G7C3L12CGCG2CO3M11 3O14 \n"
"4 2M2G3C4G2M10G5C5L3f6L4C6GCG5C4GCGO2MO8 3O16 \n"
"4 5M2G5CGCL14f4L4C12G7C8GCGO2MO5 3O18 \n"
"4 O8M2G3CL3f2L5C19G6C8G4C3GCG4M2 3O20 \n"
"5 O5M3G2M3G3L2C19GC3GC3G11C8GCG5MO22 \n"
"7 OMG4M2G2MGCLCL2C18G5C7L2C9G3CG2MG3MO23 \n"
"8 OG2C2G5MG10C2GCG5C3L5f3L3C10G3CG7MO25 \n"
"9 OM2C2LC2G2MG8C4L9f3L3C11G3C2G7M2O27 \n"
"11 M2GC5LC3L11f4L6C9G4C2G9MO30 \n"
"12 OM3G2C5Lf6L10CGC5G6CG2MOMO5M2O33 \n"
"14 M6G14C2GC2G9C2G2M4O4M3O36 \n"
"15 OM7G18C3G3M4O4M4O40 \n"
"18 O3M5G3C7G13M4O46 \n"
"20 2O21M4O53 \n"
"23 3OM13O60 "
};

const IMG EQUAL_SIM = { 16,10,
"15 \n"
" 12_2 \n"
"/11_/\\ \n"
"\\11_\\/ \n"
"15 \n"
" 12_2 \n"
"/11_/\\ \n"
"\\11_\\/ \n"
"15 \n"
"15 "
};

const IMG PLUS = { 22,10,
"7 7+7 \n"
"7 +5:+7 \n"
"7 +5:+7 \n"
" 7+5:7+ \n"
" +17:+ \n"
" +17:+ \n"
" 7+5:7+ \n"
"7 +5:+7 \n"
"7 +5:+7 \n"
"7 7+6 "
};

const IMG TOILET_PAPER = { 29,24,
"15 _\n"
"6 . -2 ' '3 '2 ' -.\n"
"3 . '7 _,._7 ' .\n"
" ,'8 ;'4 \";8 ',\n"
" |'9 ',_ ,-'8 .|\n"
" | '.10 '9 .2 |\n"
" |3 ' ,13 . '4 |\n"
" |3 |3 ' - . _ . -|7 |\n"
" |15 '. |7 |\n"
" |3 |13 '.7 |\n"
" |19 '.5 |\n"
" |3 |16 .,4 |\n"
" |20 . ,3 |\n"
" |3 |15 .2 '3 |\n"
" |18 .3 '3 |\n"
" |3 |12 .4 '4 |\n"
" !.14 '4 '4 .'\n"
"3 '.|11 '3 ,3 .\n"
"5 ' ,8 '3 ,. '\n"
"9 ' - . ,2 .-\n"
"14 ,2 .\n"
"13 , .4 :F_P:\n"
"12 , .\n"
"12 ,'"
};

const IMG STAY = { 93,22,
"10 5_16 5_20 5_16 5_10 \n"
"9 /\\4 \\14 /\\4 \\18 /\\4 \\14 |\\4 \\9 \n"
"8 /2:\\4 \\12 /2:\\4 \\16 /2:\\4 \\13 |:\\4_\\8 \n"
"7 /4:\\4 \\11 \\3:\\4 \\14 /4:\\4 \\12 |2:|3 |8 \n"
"6 /6:\\4 \\11 \\3:\\4 \\12 /6:\\4 \\11 |2:|3 |8 \n"
"5 /3:/\\3:\\4 \\11 \\3:\\4 \\10 /3:/\\3:\\4 \\10 |2:|3 |8 \n"
"4 /3:/2_\\3:\\4 \\11 \\3:\\4 \\8 /3:/2_\\3:\\4 \\9 |2:|3 |8 \n"
"4 \\3:\\3 \\3:\\4 \\10 /4:\\4 \\6 /4:\\3 \\3:\\4 \\8 |2:|3 |8 \n"
"2 3_\\3:\\3 \\3:\\4 \\8 /6:\\4 \\4 /6:\\3 \\3:\\4 \\7 |2:|3_|6_2 \n"
" /\\3 \\3:\\3 \\3:\\4 \\6 /3:/\\3:\\4 \\2 /3:/\\3:\\3 \\3:\\4 \\6 /8:\\4 \\ \n"
"/2:\\3 \\3:\\3 \\3:\\4_\\4 /3:/2 \\3:\\4_\\/3:/2 \\3:\\3 \\3:\\4_\\4 /10:\\4_\\\n"
"\\3:\\3 \\3:\\3 \\2:/4 /3 /3:/4 \\2:/4 /\\2:/4 \\3:\\2 /3:/4 /3 /3:/4~/2~6 \n"
" \\3:\\3 \\3:\\3 \\/4_/3 /3:/4 / \\/4_/2 \\/4_/ \\3:\\/3:/4 /3 /3:/4 /9 \n"
"2 \\3:\\3 \\3:\\4 \\6 /3:/4 /20 \\6:/4 /3 /3:/4 /10 \n"
"3 \\3:\\3 \\3:\\4_\\4 /3:/4 /22 \\4:/4 /3 /3:/4 /11 \n"
"4 \\3:\\2 /3:/4 /4 \\2:/4 /23 /3:/4 /4 \\2:/4 /12 \n"
"5 \\3:\\/3:/4 /6 \\/4_/23 /3:/4 /6 \\/4_/13 \n"
"6 \\6:/4 /36 /3:/4 /27 \n"
"7 \\4:/4 /36 /3:/4 /28 \n"
"8 \\2:/4 /37 \\2:/4 /29 \n"
"9 \\/4_/39 \\/4_/30 \n"
"92 "
};

const IMG HOME = { 50,21,
"8 )\n"
"7 (2 (14 .^.\n"
"8 \\) )11 .'.^.'.\n"
"9 (/10 .'.'3-'.'.\n"
"8 _\\)_7 .'.'7-'.'.\n"
"7 (2_)()4 .'.'-,7=.-'.'.\n"
"7 (_)2_)2 .'.'3-|3 |3 |3-'.'.\n"
"7 (2_)_),'.'5-|3 |3 |5-'.'.\n"
"7 ()2_.'.'7-|3_|3_|7-'.'.\n"
"7 (_.'.'27-'.'.\n"
"7 .'.'31-'.'.\n"
"6 5\"|4=2.4=.7=.4=2.4=|5\"\n"
"7 ()_)|4 2|4 |.5-.|4 2|4 |\n"
"7 (_)_|4 2|4 2|5 2|4 2|4 |\n"
"7 (3.|4_2|4_2|5_2|4_2|4_|\n"
"6 (_)_(|10-| 5_o|10-|\n"
"6 (_)(_|10-2|5 2|10-|\n"
"6 (2_)(|10-2|5_2|10-|\n"
"6 (_)(_|9-|9\"|9-|\n"
"6 ()()(|8-|11\"|8-|\n"
"Zot-wWU2wuw|2w2Ww2u|13\"|uwuw2uW|wu2w2uwu"
};

const IMG TXT1 = { 91,16,
"5 _33 _5 _11 _11 _20 \n"
"4 | |31 | |3 | |9 | |9 | |19 \n"
"4 | |5 3_2 _ 2_3 2_ _2 3_2 3_| |_2 | |2_3 3_ | |_3 _2 2_| | 2_ _ _3 _8 \n"
"4 | |4 / _ \\| '_ \\ / _` |/ _ \\/ 2_| 2_| | '_ \\ / _ \\| | | | |/ _` |/ _` | | | |7 \n"
"4 | |3_| (_) | | | | (_| |2 2_/\\2_ \\ |_2 | | | | (_) | | |_| | (_| | (_| | |_| |7 \n"
"4 \\5_/\\3_/|_| |_|\\2_, |\\3_2|3_/\\2_| |_| |_|\\3_/|_|\\2_, |\\2_,_|\\2_,_|\\2_, |S7 \n"
"24 2_/ |31 2_/ |13 2_/ |7 \n"
"23 |3_/31 |3_/13 |3_/8 \n"
" 5_33 _11 _36 2_\n"
"|_3 _|31 | |9 | |30 _3 / /\n"
"2 | |4 _ 2_ 3_3 3_2 2_ _ _ 2_4 | |2_3 3_ | |_3 _ _3 _2 3_2 2_ _ _ 2_2 (_) | | \n"
"2 | |3 | '_ ` _ \\ / _ \\/ _` | '_ \\3 | '_ \\ / _ \\| | | | | | | |/ _ \\/ _` | '2_|5 | | \n"
" _| |_2 | | | | | |2 2_/ (_| | | | |2 | | | | (_) | | |_| | |_| |2 2_/ (_| | |5 _2 | | \n"
" \\3_/2 |_| |_| |_|\\3_|\\2_,_|_| |_|2 |_| |_|\\3_/|_|\\2_, |\\2_, |\\3_|\\2_,_|_|4 (_) | | \n"
"54 2_/ | 2_/ |22 \\_\\\n"
"53 |3_/ |3_/26 "
};

const IMG SYRINGE = { 52,7,
"39 |\n"
"17 ,12-=8-|11_|\n"
"-13=3%|9 |2 |6_|_|11_|\n"
"17 | | | | | | 3| | | | |11_|\n"
"17 `12-=8-|11 |\n"
"39 |\n"
""
};

const IMG TH_NW_HP = { 117,12,
"3 2_6 2_64 2_37 \n"
"2 |2 \\4 |2 \\62 |2 \\36 \n"
" _| 2$_3 | 2$4_4 6_9 7_4 6_3 2_3 2_3 2_7 | 2$4_4 6_4 6_4 6_2 \n"
"|3 2$ \\2 | 2$4 \\2 /6 \\7 |7 \\2 /6 \\ |2 \\ |2 \\ |2 \\6 | 2$4 \\2 /6 \\2 /6 \\2 /6 \\ \n"
" \\6$2 | 7$\\|2 6$\\6 | 7$\\|2 6$\\| 2$ | 2$ | 2$6 | 7$\\|2 6$\\|2 6$\\|2 6$\\\n"
"2 | 2$ 2_ | 2$2 | 2$| 2$4 2$6 | 2$2 | 2$| 2$4 2$| 2$ | 2$ | 2$6 | 2$2 | 2$| 2$2 | 2$| 2$2 | 2$| 2$4 2$\n"
"2 | 2$|2 \\| 2$2 | 2$| 8$6 | 2$2 | 2$| 8$| 2$_/ 2$_/ 2$6 | 2$2 | 2$| 2$2_/ 2$| 2$2_/ 2$| 8$\n"
"3 \\2$2 2$| 2$2 | 2$ \\2$5 \\6 | 2$2 | 2$ \\2$5 \\ \\2$3 2$3 2$6 | 2$2 | 2$ \\2$4 2$| 2$4 2$ \\2$5 \\\n"
"4 \\4$2 \\2$3 \\2$2 \\7$7 \\2$3 \\2$2 \\7$2 \\5$\\4$8 \\2$3 \\2$2 \\6$ | 7$3 \\7$\n"
"96 | 2$16 \n"
"96 | 2$16 \n"
"97 \\2$16 "
};

const IMG BEACH = { 61,40,
"27 5#\n"
"23 7#\n"
"12 6#4 8#7 5#\n"
"8 11#/5#\\5#2 13#\n"
"4 12#/10#2-21#\n"
"2 4#9 22#10 5#\n"
" 2#10 4#6 10#/2@14 3#\n"
"#10 4#8 ,-.2#/`.#\\5#15 2#\n"
"10 3#9 /2 |$/2 |,-. 4#17 #\n"
"9 2#11 \\_,'$\\_,'|2 \\2 3#\n"
"9 #14 \\_5$`._/3 2#\n"
"26 5$_/5 2#\n"
"26 5$8 #\n"
"26 5$\n"
"26 5$\n"
"26 5$\n"
"26 5$\n"
"25 5$\n"
"25 5$\n"
"25 5$\n"
"25 5$8 3_\n"
"25 5$4 _.-'3 `-._\n"
"24 5$3 ,'11 `.\n"
"24 5$2 /15 \\\n"
"23~5$3~'16~`12~\n"
"3 ~6 ~2 ~4 ~2 ~ 5$2 ~3 ~7 ~10 ~\n"
"7 ~ ~6 .o,4 5$5 ~4 ~2 ~8 ~\n"
"2 ~12 ~ ^3 ~ 5$~8 6_4 ~8 ~\n"
"23_5$8_|7\\17_\n"
"23 5$8 |>7\\\n"
"4 6_13 5$8 |2>7\\\n"
"3 \\Q%=/\\,\\12 5$7 /\\2>|5#|\n"
"4 `6-`11 5$6 /=|\\>|5#|\n"
"23 5$8 2|\\|5#|\n"
"22 7$10 2|3\"2|\n"
"22 7$10 2|3 2|\n"
"21 9$\n"
"21\"9$31\"\n"
"24 3$12 -Shimrod\n"
""
};

const IMG AND = { 3,1,
"AND\n"
};

const IMG HPNY1 = { 66,8,
"64 _\n"
" _3 _21 _4 _13 _2 _13 | |\n"
"/|3 |\\20 |\\3 |\\12 /2 |\\12 |_|\n"
" |3_|2 _3 _4 _9 | \\2 |2 _9 /3 |2 _3 _2 ,_3 _\n"
" |3 | / | | \\2 | \\2 / |3 |2 \\ | /_\\ / / |2 \\3_|2/_\\ / | | ` / \\\n"
"\\|3 |/\\_|/|_/_/|_/_/\\_|2 \\|3 \\| \\2_/\\_\\_|5 /| \\2_/\\_|/|3 \\_/\n"
"5 '5 |4 |5 /|8 `14 ( |8 \n"
"11 |4 |5 \\|24 \\|4 "
};

const IMG CREDIT = { 133,27,
"42 _8 _13 5_22 5_20 \n"
"41 | |6 | |11 /2 2_ \\20 |2 _2 |19 \n"
"29 3_ 3_3 2_| | 3_2 | |2_2 _3 _2 | /2 \\/ 3_ _ 2_ 3_2 _3 _| |/' |19 \n"
"28 / 2_/ _ \\ / _` |/ _ \\ | '_ \\| | | | | |4 / _ \\ '_ ` _ \\| | | |2 /| |19 \n"
"27 | (_| (_) | (_| |2 2_/ | |_) | |_| | | \\2_/\\2 2_/ | | | | | |_| \\ |_/ /19 \n"
"28 \\3_\\3_/ \\2_,_|\\3_| |_.2_/ \\2_, |2 \\4_/\\3_|_| |_| |_|\\2_,_|\\3_/20 \n"
"58 2_/ |54 \n"
"57 |3_/55 \n"
"31 ASC2I ART BY:68 \n"
"54 _ _18 _40 \n"
"53 (_|_)16 | |39 \n"
"40 2_ _ 3_2 3_ _ _3 3_ 3_2 _3 _| | 2_36 \n"
"39 / _` / 2_|/ 2_| | | / 2_/ _ \\| | | | |/ /36 \n"
"38 | (_| \\2_ \\ (2_| | 2| (_| (_) | |_| |3 <37 \n"
"39 \\2_,_|3_/\\3_|_|_(_)3_\\3_(_)2_,_|_|\\_\\36 \n"
"49 \n"
"39 \n"
"31 AND2\n"
"13 _13 _ _29 2_9 2_ _30 3_19 \n"
"12 | |11 (_) |27 / /8 / _| |28 / / |19 \n"
" _ 2_3 2_ _| |_ 3_2 _ 2_ _| | 2_2 3_ 3_2 _ 2_ 3_4 / /2_2 3_ | |_| |3_6 4_ _ _ 2_ 3_3 / /| |_ 2_ _2 2_ _2 2_ _ \n"
"/ '_ \\ / _` | 2_/ _ \\| '2_| | |/ / / 2_/ _ \\| '_ ` _ \\2 / / 2_|/ _ \\|2 _| 2_\\ \\ /\\ / / _` | '2_/ _ \\ / / | 2_/ _` |/ _` |/ _` |\n"
"| |_) | (_| | 2| (_) | |2 | |3 < | (_| (_) | | | | | |/ /\\2_ \\ (_) | | | |_ \\ V2 V / (_| | | |2 2_2/ /2 | 2| (_| | (_| | (_| |\n"
"| .2_/ \\2_,_|\\2_\\3_/|_|2 | |_|\\_(_)3_\\3_/|_| |_| |_/_/ |3_/\\3_/|_|2 \\2_| \\_/\\_/ \\2_,_|_|2 \\3_/_/4 \\2_\\2_,_|\\2_,_|\\2_, |\n"
"| |22 _/ |93 2_/ |\n"
"|_|21 |2_/93 |3_/7 "
};

#include <memory>
//#include <thread> //just forget it

#include <string>
#include <vector>

#include <windows.h>
#include <chrono>

#define WIN32_LEAN_AND_MEAN

//#define DEBUG

#define WIN_WIDTH 1200
#ifdef DEBUG
    #define WIN_HEIGH 810
#else
    #define WIN_HEIGH 800
#endif // DEBUG

#define SCREEN_WIDTH 145
#define SCREEN_HEIGHT 47

using namespace std;
//*********************************** BASED FUNCTION ******************************************
COORD dwBufferSize = { SCREEN_WIDTH + 1,SCREEN_HEIGHT + 1 };
COORD dwBufferCoord = { 0, 0 };
SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
static CHAR_INFO buffer[SCREEN_HEIGHT + 1][SCREEN_WIDTH + 1];
HANDLE hOutput;
void Setup()
{
    srand((unsigned int)time(NULL));
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, WIN_WIDTH, WIN_HEIGH, TRUE);
    COORD pos = { 0, 0 };
    SetConsoleCursorPosition(console, pos);
    hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize, dwBufferCoord, &rcRegion);
}

int random(int begin, int end)
{
    return rand() % end + begin;
}

void ClearScreen() {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            buffer[i][j].Char.AsciiChar = ' ';
            buffer[i][j].Attributes = 1;
        }
            
    }
    return;
}

//     colors:
//     0 = Black
//     1 = Blue
//     2 = Green
//     3 = Cyan
//     4 = Red
//     5 = Magenta
//     6 = Yellow
//     7 = LightGray
//     8 = DarkGray
//     9 = LightBlue
//     10 = LightGreen
//     11 = LightCyan
//     12 = LightRed
//     13 = LightMagenta
//     14 = LightYellow
//     15 = White
//     16 = random crazy color 

void printAtXY(int x, int y,const string &str, WORD color)
{
    if (y > SCREEN_HEIGHT)
        return;
    for (int j = x; int(j-x) < int(str.length()) && j < SCREEN_WIDTH; j++) 
    {
        buffer[y][j].Char.AsciiChar = str[j-x];
        if (color == 16)
            buffer[y][j].Attributes = random(1, 15);
        else
            buffer[y][j].Attributes = color;
    }
}

void drawpixel(unsigned char x, unsigned char y, unsigned char Color, string Ch = "O") 
{
    if (x<0 || x> SCREEN_WIDTH || y<0 || y>SCREEN_HEIGHT)
        return;
    printAtXY(x, y, Ch, Color);
}

//*********************************** CHARACTER WORK *******************************************

/*
    * Print string with is renderred inorder to:
    *   * Not print if no display
    *       * no header if no need
    *       * no tail for not messing up the display
    * More idea ?
    H                   O*****  THIS IS YOUR CONSOLE *****X
    E                   *                                 *
    I  not print this   *                      PRINT THIS * BUT NOT THIS 
    G                   *                      ASLO SCOLED* BUT NOT MESS THINGS UP
    H                   Y**************WIDTH***************
*/

void printxy(const string &ipstr, int x, int y, int color)
{
    string str;
    Decompress(ipstr, str);
    //setcolor(color);
    int x_prefix = 0,
        y_prefix = 0;

    if (x < 0) x_prefix = -x;
    if (y < 0) y_prefix = -y;

    int r_x = x + x_prefix,
        r_y = y + y_prefix;

    if (x > SCREEN_WIDTH || y > SCREEN_HEIGHT)
        return;

    int y_count = 0,
        y_res = 0;
    const int str_length = str.length();

    int start_p = 0;

    while (str_length-start_p > 0)
    {
        //str_length = str.length();
        static string out = "";
        size_t c = str.find('\n', start_p);
        if (string::npos != c)
        {
            out = str.substr(start_p, c - start_p);//+ 0?1:start_p==0
            //str = str.substr(c + 1, str_length);
            start_p = c+1;
        }
        else
        {
            out = str.substr(start_p, str_length - start_p);
            //out = str;
            start_p = str_length;
            //str = "";
        }
        
        const int out_length = out.length();
        //min trim
        if (x < 0)
            if (out_length < x_prefix)
            {
                y_count++;
                continue;
            }
            else
                out = out.substr(x_prefix, out_length - x_prefix);

        if (y + y_count < 0)
        {
            y_count++;
            y_res++;
            continue;
        }
        
        //max trim
        if (x + out_length > SCREEN_WIDTH)
            out = out.substr(0, SCREEN_WIDTH - r_x);

        if (y + y_count > SCREEN_HEIGHT)
            break;

        printAtXY(r_x, r_y + y_count-y_res, out,color);
        y_count++;
    }
}
void write()
{
    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,dwBufferCoord, &rcRegion);
}
//********************************** DRAW FUNCTION *******************************************

void drawcircle(int x, int y, int a, int b, int color, string Ch = "O"){
    int wx, wy;
    int thresh;
    int asq = a * a;
    int bsq = b * b;
    int xa, ya;

    drawpixel(x, y + b, color,Ch);
    drawpixel(x, y - b, color,Ch);

    wx = 0;
    wy = b;
    xa = 0;
    ya = asq * 2 * b;
    thresh = asq / 4 - asq * b;

    for (;;) {
        thresh += xa + bsq;

        if (thresh >= 0) {
            ya -= asq * 2;
            thresh -= ya;
            wy--;
        }

        xa += bsq * 2;
        wx++;

        if (xa >= ya)
            break;

        drawpixel(x + wx, y - wy, color, Ch);
        drawpixel(x - wx, y - wy, color, Ch);
        drawpixel(x + wx, y + wy, color, Ch);
        drawpixel(x - wx, y + wy, color, Ch);
    }

    drawpixel(x + a, y, color, Ch);
    drawpixel(x - a, y, color, Ch);

    wx = a;
    wy = 0;
    xa = bsq * 2 * a;

    ya = 0;
    thresh = bsq / 4 - bsq * a;

    for (;;) {
        thresh += ya + asq;

        if (thresh >= 0) {
            xa -= bsq * 2;
            thresh = thresh - xa;
            wx--;
        }

        ya += asq * 2;
        wy++;

        if (ya > xa)
            break;

        drawpixel(x + wx, y - wy, color, Ch);
        drawpixel(x - wx, y - wy, color, Ch);
        drawpixel(x + wx, y + wy, color, Ch);
        drawpixel(x - wx, y + wy, color, Ch);
    }
    write();
}
// *************************** FUNNy FUNCTION ******************************************
class fireworld
{
private:
    int fire_time = 0;

    int fire_world_a[10], 
        fire_world_b[10], 
        fire_world_c[10];
    int n{};
public:
    fireworld(int _n)
    {
        if (_n > 10)_n = 10;
        n = _n;
    }
    void show()
    {
        fire_time++;
        switch (fire_time %5)
        {
        case 0:
            for (int i = 0; i < n; i++) {
                fire_world_a[i] = random(6, (SCREEN_WIDTH - 14));
                fire_world_b[i] = random(6, (SCREEN_HEIGHT - 14));
                fire_world_c[i] = random(1, 15);
                drawcircle(fire_world_a[i], fire_world_b[i], 2, 1, fire_world_c[i]);
            }
            break;

        case 1:
            for (int i = 0; i < n; i++) {
                drawcircle(fire_world_a[i], fire_world_b[i], 2, 1, fire_world_c[i], " ");
                drawcircle(fire_world_a[i], fire_world_b[i], 4, 2, fire_world_c[i]);
            }
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                drawcircle(fire_world_a[i], fire_world_b[i], 4, 2, fire_world_c[i], " ");
                drawcircle(fire_world_a[i], fire_world_b[i], 6, 3, fire_world_c[i]);
            }
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                drawcircle(fire_world_a[i], fire_world_b[i], 6, 3, fire_world_c[i], " ");
                drawcircle(fire_world_a[i], fire_world_b[i], 8, 4, fire_world_c[i]);
            }
            break;
        case 4:
            for (int i = 0; i < n; i++)
                drawcircle(fire_world_a[i], fire_world_b[i], 8, 4, fire_world_c[i], " ");
            break;
        default:
            break;
        }
        if (fire_time > 5 * 100)
            fire_time = 0;
    }
};

class Sequence
{
public:

    struct IMGPOS
    {
        const IMG& img;
        int x;
        int y;
        int color;
        //string acc;
    };

    vector<IMGPOS>* imgs_pos = new vector<IMGPOS>;

    int coord_obj, sequence_w, sequence_h;
    int _fps = 25;
    int _fireworld;
    
    Sequence(const IMG &img, const int fps = 25,int color = 16, int __fireworld = 0)
    {
        sequence_w = img.width;
        sequence_h = img.height;
        IMGPOS _img = {img,0,0,color};
        coord_obj = 0;
        imgs_pos->push_back(_img);
        _fps = fps;
        _fireworld = __fireworld;
        //imgs_pos->shrink_to_fit();
    }
    void AddLeftSide(Sequence& sequence, bool stay_bottom = false)
    {
        //caculate width and heigh
        int x_shift = sequence.sequence_w;
        int y_shift = 0;
        int _y_shift = 0; // shift the sequence

        this->sequence_w += sequence.sequence_w;
        if (this->sequence_h < sequence.sequence_h)
        {
            y_shift = (sequence.sequence_h - this->sequence_h) / 2;
            
            this->sequence_h = sequence.sequence_h;
        }
        else
        {
            _y_shift = (this->sequence_h - sequence.sequence_h) / 2;
            if (stay_bottom) //lol ...
                _y_shift = this->sequence_h - sequence.sequence_h/2 -1;
        }
        //update this obj

        for (size_t i = 0; i < imgs_pos->size(); i++)
        {
            imgs_pos->at(i).x += x_shift;
            imgs_pos->at(i).y += y_shift;
        }
        //push_back
        size_t lastsize = sequence.imgs_pos->size();
        for (size_t i = 0; i < lastsize; i++)
        {
            int bk_y = sequence.imgs_pos->at(i).y;
            sequence.imgs_pos->at(i).y += _y_shift;
            imgs_pos->push_back(sequence.imgs_pos->at(i));
            sequence.imgs_pos->at(i).y = bk_y;
        }
    }
    void AddBottomSide(Sequence &sequence)
    {
        //caculate width and heigh
        int x_shift = 0;
        int y_shift = this->sequence_h;
        int _x_shift = 0; // shift the sequence

        this->sequence_h += sequence.sequence_h;

        if (this->sequence_w < sequence.sequence_w)
        {
            x_shift = (sequence.sequence_w - this->sequence_w) / 2;
            this->sequence_w = sequence.sequence_w;

            //update this->sequence
            for (size_t i = 0; i < imgs_pos->size(); i++)
                imgs_pos->at(i).x += x_shift;
        }
        else
        {
            _x_shift = (this->sequence_w - sequence.sequence_w) / 2;
        }
            
        //push_back
        size_t lastsize = sequence.imgs_pos->size();
        for (size_t i = 0; i < lastsize; i++)
        {   //update heigh
            int bk_y = sequence.imgs_pos->at(i).y;
            int bk_x = sequence.imgs_pos->at(i).x;

            sequence.imgs_pos->at(i).y += y_shift;
            sequence.imgs_pos->at(i).x += _x_shift;

            imgs_pos->push_back(sequence.imgs_pos->at(i));

            sequence.imgs_pos->at(i).y = bk_y;
            sequence.imgs_pos->at(i).x = bk_x;
        }
    }
    void AddBottomSide(const IMG& img, int color = 16) {
        Sequence* sequence = new Sequence(img,25,color);
        this->AddBottomSide(*sequence);
        delete sequence;
    }
    void AddLeftSide(const IMG& img, int color = 16, bool stay_bottom = false) {
        Sequence* sequence = new Sequence(img, 25, color);
        this->AddLeftSide(*sequence, stay_bottom);
        delete sequence;
    }
    void AnimateLeftToRight()
    {
        ;
        fireworld* fire = new fireworld(_fireworld);
        clock_t start;
        clock_t duration = 0;
        clock_t fps_t = (1000 / _fps);
        int center = (SCREEN_HEIGHT - sequence_h) / 2;
        for (int i = -sequence_w; i < SCREEN_WIDTH + 1; i += 1)
        {
            start = clock();
            ClearScreen();
            for (int j = 0; j < imgs_pos->size(); j++)
                //check if object need render :v
                if (i + (imgs_pos->at(j).x + imgs_pos->at(j).img.width) > 0 &&
                    i + imgs_pos->at(j).x < SCREEN_WIDTH)

                    //printxy(imgs_pos->at(j).img, i + imgs_pos->at(j).x, imgs_pos->at(j).y, random(1, 15));
                    printxy(imgs_pos->at(j).img.img, i + imgs_pos->at(j).x, center + imgs_pos->at(j).y, imgs_pos->at(j).color);

#ifdef DEBUG
            printAtXY(0, SCREEN_HEIGHT, (string)"Operation took " + to_string(duration) + " Milliseconds " + to_string(i), 3);
            if (duration < fps_t)
                printAtXY(0, 0, (string)"          ", 10);
            else
                printAtXY(0, 0, (string)" Overload !", 10);
#endif // DEBUG
            if (_fireworld != 0)
                fire->show();
            write();
            duration = (clock() - start);
            if (duration < fps_t)
                Sleep(fps_t - duration);
        }
    }
    void AnimateRightToLeft()
    {
        ;
        unique_ptr<fireworld> fire(new fireworld(_fireworld));
        clock_t start;
        clock_t duration = 0;
        clock_t fps_t = (1000 / _fps);
        int center = (SCREEN_HEIGHT - sequence_h) / 2;
        for (int i = SCREEN_WIDTH+1; i > -sequence_w; i--)
        {
            start = clock(); 
            ClearScreen();
            int color = 3;//random(1, 16);
            for (int j = 0; j < imgs_pos->size(); j++)
                //check if object need render :v
                if (i + (imgs_pos->at(j).x + imgs_pos->at(j).img.width) > 0 &&
                    i + imgs_pos->at(j).x < SCREEN_WIDTH)
                        printxy(imgs_pos->at(j).img.img, i + imgs_pos->at(j).x, center + imgs_pos->at(j).y, imgs_pos->at(j).color);

#ifdef DEBUG
            printAtXY(0, SCREEN_HEIGHT, (string)"Operation took " + to_string(duration) + " Milliseconds " + to_string(i), 3);
            if (duration < fps_t)
                printAtXY(0, 0, (string)"          ", 10);
            else
                printAtXY(0, 0, (string)" Overload !", 10);
#endif // DEBUG
            if (_fireworld != 0)
                fire->show();
            write();
            duration = (clock() - start);
            if (duration < fps_t)
                Sleep(fps_t - duration);
        }
    }
    void AnimateTopToBottom(int delay)
    {
        ;
        unique_ptr<fireworld> fire(new fireworld(_fireworld));
        clock_t start;
        clock_t duration = 0;
        clock_t fps_t = (1000 / _fps); //50
        delay = delay/fps_t; // 
        int center = (SCREEN_WIDTH-sequence_w) / 2;
        for (int i = -sequence_h; i < sequence_h + SCREEN_HEIGHT; i += 1)
        {
            if (i > (SCREEN_HEIGHT - sequence_h) / 2)
                if (delay != 0)
                {
                    delay--;
                    i--;
                }
            start = clock();

            ClearScreen();
            for (int j = 0; j < imgs_pos->size(); j++)
                //check if object need render :v
                if (i + (imgs_pos->at(j).y + imgs_pos->at(j).img.height) > 0 &&
                    i + imgs_pos->at(j).y < SCREEN_HEIGHT)
                    printxy(imgs_pos->at(j).img.img, center +imgs_pos->at(j).x,i + imgs_pos->at(j).y, imgs_pos->at(j).color);

#ifdef DEBUG
            printAtXY(0, SCREEN_HEIGHT, (string)"Operation took " + to_string(duration) + " Milliseconds " + to_string(i), 3);
            if (duration < fps_t)
                printAtXY(0, 0, (string)"          ", 10);
            else
                printAtXY(0, 0, (string)" Overload !", 10);
#endif // DEBUG
            if (_fireworld != 0)
                fire->show();
            write();
            duration = (clock() - start);
            if (duration < fps_t)
                Sleep(fps_t - duration);
        }
    }
    void AnimateTopToCenter(int delay)
    {
        ;
        unique_ptr<fireworld> fire(new fireworld(_fireworld));
        clock_t start;
        clock_t duration = 0;
        clock_t fps_t = (1000 / _fps); //50
        delay = delay / fps_t; // 
        int center = (SCREEN_WIDTH - sequence_w) / 2;
        for (int i = -sequence_h; i < (SCREEN_HEIGHT - sequence_h) / 2; i += 1)
        {
            if (i > (SCREEN_HEIGHT - sequence_h) / 2 - 2)
                if (delay != 0)
                {
                    delay--;
                    i--;
                }
            start = clock();

            ClearScreen();
            for (int j = 0; j < imgs_pos->size(); j++)
                //check if object need render :v
                if (i + (imgs_pos->at(j).y + imgs_pos->at(j).img.height) > 0 &&
                    i + imgs_pos->at(j).y < SCREEN_HEIGHT)
                    printxy(imgs_pos->at(j).img.img, center + imgs_pos->at(j).x, i + imgs_pos->at(j).y, imgs_pos->at(j).color);

#ifdef DEBUG
            printAtXY(0, SCREEN_HEIGHT, (string)"Operation took " + to_string(duration) + " Milliseconds " + to_string(i), 3);
            if (duration < fps_t)
                printAtXY(0, 0, (string)"          ", 10);
            else
                printAtXY(0, 0, (string)" Overload !", 10);
#endif // DEBUG
            if (_fireworld != 0)
                fire->show();
            write();
            duration = (clock() - start);
            if (duration < fps_t)
                Sleep(fps_t - duration);
        }
    }
    void AnimateBottomToCenter(int delay)
    {
        unique_ptr<fireworld> fire(new fireworld(_fireworld));
        clock_t start;
        clock_t duration = 0;
        clock_t fps_t = (1000 / _fps); //50
        delay = delay / fps_t; // 
        int center = (SCREEN_WIDTH - sequence_w) / 2;
        for (int i = sequence_h+SCREEN_HEIGHT; i > (SCREEN_HEIGHT - sequence_h) / 2; i -= 1)
        {
            if (i < (SCREEN_HEIGHT - sequence_h) / 2 +2)
                if (delay != 0)
                {
                    delay--;
                    i++;
                }
            start = clock();

            ClearScreen();
            for (int j = 0; j < imgs_pos->size(); j++)
                //check if object need render :v
                if (i + (imgs_pos->at(j).y + imgs_pos->at(j).img.height) > 0 &&
                    i + imgs_pos->at(j).y < SCREEN_HEIGHT)
                    printxy(imgs_pos->at(j).img.img, center + imgs_pos->at(j).x, i + imgs_pos->at(j).y, imgs_pos->at(j).color);

#ifdef DEBUG
            printAtXY(0, SCREEN_HEIGHT, (string)"Operation took " + to_string(duration) + " Milliseconds " + to_string(i), 3);
            if (duration < fps_t)
                printAtXY(0, 0, (string)"          ", 10);
            else
                printAtXY(0, 0, (string)" Overload !", 10);
#endif // DEBUG
            if (_fireworld != 0)
                fire->show();
            write();
            duration = (clock() - start);
            if (duration < fps_t)
                Sleep(fps_t - duration);
        }
    }
    void AnimateCenterToRight()
    {
        ;
        unique_ptr<fireworld> fire(new fireworld(_fireworld));
        
        clock_t start;
        clock_t duration = 0;
        clock_t fps_t = (1000 / _fps);
        int center = (SCREEN_HEIGHT - sequence_h) / 2;
        int start_x = (SCREEN_WIDTH - imgs_pos->back().img.width) / 2;
        for (int i = start_x; i > -sequence_w; i--)
        {
            start = clock();
            ClearScreen();
            for (int j = 0; j < imgs_pos->size(); j++)
                 printxy(imgs_pos->at(j).img.img, 
                     i + imgs_pos->at(j).x, 
                     center + imgs_pos->at(j).y, 
                     imgs_pos->at(j).color);

#ifdef DEBUG
            printAtXY(0, SCREEN_HEIGHT, (string)"Operation took " + to_string(duration) + " Milliseconds " + to_string(i), 3);
            if (duration < fps_t)
                printAtXY(0, 0, (string)"          ", 10);
            else
                printAtXY(0, 0, (string)" Overload !", 10);
#endif // DEBUG
            if (_fireworld != 0)
                fire->show();
            write();
            duration = (clock() - start);
            if (duration < fps_t)
                Sleep(fps_t - duration);
        }
    }
    void AnimateCenterToCenter(int delay)
    {
        ;
        unique_ptr<fireworld> fire(new fireworld(_fireworld));

        clock_t start;
        clock_t duration = 0;
        clock_t fps_t = (1000 / _fps);
        delay = delay / fps_t;
        int center = (SCREEN_HEIGHT - sequence_h) / 2;
        int start_x = (SCREEN_WIDTH - imgs_pos->back().img.width) / 2;
        int end_x = (SCREEN_WIDTH - (sequence_w + imgs_pos->front().x)) / 2 + 37;
        for (int i = start_x; i > end_x; i--)
        {
            if (i < end_x + 2)
                if (delay != 0)
                {
                    delay--;
                    i++;
                }
            start = clock();
            ClearScreen();
            for (int j = 0; j < imgs_pos->size(); j++)
                printxy(imgs_pos->at(j).img.img,
                    i + imgs_pos->at(j).x,
                    center + imgs_pos->at(j).y,
                    imgs_pos->at(j).color);

#ifdef DEBUG
            printAtXY(0, SCREEN_HEIGHT, (string)"Operation took " + to_string(duration) + " Milliseconds " + to_string(i), 3);
            if (duration < fps_t)
                printAtXY(0, 0, (string)"          ", 10);
            else
                printAtXY(0, 0, (string)" Overload !", 10);
#endif // DEBUG
            if (_fireworld != 0)
                fire->show();
            write();
            duration = (clock() - start);
            if (duration < fps_t)
                Sleep(fps_t - duration);
        }
    }
    void ShowCenter(int delay){
        ;
        unique_ptr<fireworld> fire(new fireworld(_fireworld));
        clock_t start;
        clock_t duration = 0;
        clock_t fps_t = (1000 / _fps); //50
        delay = delay / fps_t; // 
        int center_x = (SCREEN_WIDTH - sequence_w) / 2;
        int center_Y = (SCREEN_HEIGHT - sequence_h) / 2;
        while (delay != 0)
        {
            delay--;
            start = clock();
            ClearScreen();
            for (int j = 0; j < imgs_pos->size(); j++)
                    printxy(imgs_pos->at(j).img.img, 
                        center_x + imgs_pos->at(j).x,
                        center_Y + imgs_pos->at(j).y,
                        imgs_pos->at(j).color);

#ifdef DEBUG
            printAtXY(0, SCREEN_HEIGHT, (string)"Operation took " + to_string(duration) + " Milliseconds " + to_string(delay), 3);
            if (duration < fps_t)
                printAtXY(0, 0, (string)"          ", 10);
            else
                printAtXY(0, 0, (string)" Overload !", 10);
#endif // DEBUG
            if (_fireworld != 0)
                fire->show();
            write();
            duration = (clock() - start);
            if (duration < fps_t)
                Sleep(fps_t - duration);
        }
    }
};
   
#ifdef PLAY_SOUND
    #pragma comment(lib, "winmm.lib")
#endif

int main(void)
{
    #ifdef PLAY_SOUND
        PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS);
    #endif
    Setup();
    
    #ifdef PLAY_SOUND
        PlaySound(TEXT(SONG_NAME), NULL, SND_ASYNC);
    #endif
    const IMG EMPTY = {11,5};
        // sequence 1
    unique_ptr<Sequence> BeginSequence(new Sequence(SANTA_MERRYCHRISTMAS,15,4));
    Sequence usequence(TWTW);
    BeginSequence->AddBottomSide(usequence);
    BeginSequence->AnimateTopToCenter(1200);
        // sequence 2
    Sequence sequence2(CHRISTMAS_TREE_00, 70, 16);
    sequence2.AddLeftSide(EMPTY);
    sequence2.AddLeftSide(TWTW,8);
    sequence2.AddLeftSide(EQUAL_SIM,16); 
    sequence2.AddLeftSide(CHRISTMAS_TREE_01, 2, true);
    sequence2.AddLeftSide(TOILET_PAPER, 15);
    sequence2.AddLeftSide(CHRISTMAS_TREE_02, 2, true);
    sequence2.AddLeftSide(PLUS, 16);
    sequence2.AddLeftSide(CHRISTMAS_TREE_03, 2, true);
    sequence2.AddLeftSide(MASK, 1);
    sequence2.AddLeftSide(CHRISTMAS_TREE_04, 2, true);
    sequence2.AnimateLeftToRight();
    
        // sequence 3 
    Sequence sequence3(TXT1, 60, 3);
    sequence3.ShowCenter(1000);
        // sequence 4 
    Sequence sequence4(HOME, 70, 3);
    sequence4.AddLeftSide(EMPTY);
    sequence4.AddLeftSide(STAY, 8);
    sequence4.AddLeftSide(EMPTY);
    sequence4.AddLeftSide(VILLAGE , 13);
    sequence4.AddLeftSide(EMPTY);
    sequence4.AddLeftSide(sequence3);
    sequence4.AnimateCenterToRight();
        // sequence 5 
    Sequence sequence5(TWTW, 60, 3);
    sequence5.ShowCenter(1000);
    Sequence sequence51(DYNAMITE, 60,12); //EXPLOSION
    sequence51.ShowCenter(300);
    Sequence sequence52(EXPLOSION, 60, 12, 5);
    sequence52.ShowCenter(500);
    Sequence sequence53(TWTW1, 60, 14);
    sequence53.ShowCenter(1000);
        // sequence 6 
    Sequence sequence6(SANTA_FACE, 60, 4);
    Sequence newhope(SYRINGE, 60, 10);
    newhope.AddBottomSide(TH_NW_HP, 6);
    sequence6.AddLeftSide(newhope);
    sequence6.AddLeftSide(EMPTY);
    sequence6.AddLeftSide(SANTA_FACE, 4);
    sequence6.AddLeftSide(EMPTY);
    sequence6.AddLeftSide(EMPTY);
    sequence6.AddLeftSide(EMPTY);
    sequence6.AddLeftSide(EMPTY);
    sequence6.AddLeftSide(EMPTY);
    sequence6.AddLeftSide(sequence53);
    sequence6.AnimateCenterToRight();
        // sequence 7 
    Sequence sequence7(COVID, 60, 3);
    sequence7.ShowCenter(1000);
    Sequence sequence71(DYNAMITE, 60, 12); //EXPLOSION
    sequence71.ShowCenter(200);
    Sequence sequence72(EXPLOSION, 60, 12, 5);
    sequence72.ShowCenter(600);
    Sequence sequence73(MOTOR, 50, 3);
    sequence73.ShowCenter(500);
        // sequence 8
    Sequence sequence8(EMPTY, 60, 0);
    Sequence sequence81(HPNY, 60, 12,10);
    sequence81.AddBottomSide(TWTW1);
    sequence8.AddLeftSide(sequence81);
    sequence8.AddLeftSide(EMPTY);
    sequence8.AddLeftSide(EMPTY);
    sequence8.AddLeftSide(EMPTY);
    sequence8.AddLeftSide(EMPTY);
    sequence8.AddLeftSide(EMPTY);
    sequence8.AddLeftSide(BEACH,14);
    sequence8.AddLeftSide(EMPTY);
    sequence8.AddLeftSide(EMPTY);
    sequence8.AddLeftSide(EMPTY);
    sequence8.AddLeftSide(sequence73);
    sequence8.AnimateCenterToCenter(1000);
    sequence81.ShowCenter(1000);
        // sequence 9
    Sequence sequence9(SANTA_MERRYCHRISTMAS, 21, 23);
    sequence9.AddBottomSide(AND, 6);
    sequence9.AddBottomSide(HPNY1, 6);
    sequence9.AnimateBottomToCenter(0);
    Sleep(10000);
//credit :D
    #ifdef PLAY_SOUND
        PlaySound(NULL, 0, 0);
    #endif
    ClearScreen();
    write();
    #ifdef PLAY_SOUND
        PlaySound(TEXT(SONG_NAME), NULL, SND_ASYNC | SND_LOOP);//SND_FILENAME SND_NOSTOP SND_ASYNC
    #endif

    Sequence End(CREDIT, 60, 15);
    End.ShowCenter(7000);

    Sequence EndSequence(GLOBE, 10);
    EndSequence.AddLeftSide(TWTW);
    EndSequence.AddLeftSide(TWTW1);
    EndSequence.AddLeftSide(HPNY);
    EndSequence.AddLeftSide(MC);
    EndSequence.AddLeftSide(HAND);
    EndSequence.AddLeftSide(VILLAGE);
    EndSequence.AddLeftSide(MOTOR);
    EndSequence.AddLeftSide(EXPLOSION);
    EndSequence.AddLeftSide(DYNAMITE);
    EndSequence.AddLeftSide(SANTA_FACE);
    EndSequence.AddLeftSide(SANTA_MERRYCHRISTMAS);
    EndSequence.AddLeftSide(CHRISTMAS_TREE_00);
    EndSequence.AddLeftSide(CHRISTMAS_TREE_01);
    EndSequence.AddLeftSide(CHRISTMAS_TREE_02);
    EndSequence.AddLeftSide(CHRISTMAS_TREE_03);
    EndSequence.AddLeftSide(CHRISTMAS_TREE_04);
    EndSequence.AddLeftSide(MASK);
    EndSequence.AddLeftSide(PLUS);
    EndSequence.AddLeftSide(EQUAL_SIM);
    EndSequence.AddLeftSide(TOILET_PAPER);
    EndSequence.AddLeftSide(STAY);
    EndSequence.AddLeftSide(HOME);
    EndSequence.AddLeftSide(TH_NW_HP);
    EndSequence.AddLeftSide(End);
    EndSequence.AnimateCenterToRight();

    #ifdef PLAY_SOUND
        PlaySound(NULL, 0, 0);
    #endif
    return 0;
}
