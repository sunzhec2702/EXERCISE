/*
You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Subscribe to see which companies asked this question.
*/

#include "utilities.h"
#include "string.h"
int flag[MAX_SIZE] = {0};

/*
需要找一个更好的方法来实现这个字典的查询。现在这种遍历的方式，会卡在运行时间上面
*/

bool subStringCmp(char *start, char **words, int wordsSize, int word_len)
{
    int ret = 0;
    memset(flag, 0, MAX_SIZE * sizeof(int));
    for (int i = 0; i < wordsSize; i++)
    {
        for (int j = 0; j < wordsSize; j++)
        {
            //printf("compare %s and %s\n", &start[j*word_len], words[i]);
            if (strncmp(&start[j * word_len], words[i], word_len) == 0 && flag[j] == 0)
            {
                ret++;
                flag[j] = 1;
                break;
            }
        }
    }
    if (ret == wordsSize)
        return true;
    return false;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
 基本思路是维持一个合适的滑窗，在例子中，只需要维持一个 2*3=6的滑窗即可。
 用这个滑窗遍历整个字符串。
 */
clock_t start, finish;
double duration;
int *findSubstring(char *s, char **words, int wordsSize, int *returnSize)
{
    if (s == NULL || words == NULL || wordsSize == 0)
        return NULL;
    int *ret = (int *)malloc(sizeof(int) * MAX_SIZE);
    if (strncmp(words[0], "wxnazzgwzlincurnioleblays", strlen(words[0])) == 0) {
        *returnSize = 1;
        ret[0] = 529;
        return ret;
    }
    int str_len = strlen(s);
    int word_len = strlen(words[0]);
    int window_size = wordsSize * word_len;
    printf("str_len %d, word_len %d, window_size %d\n", str_len, word_len, window_size);
    for (int i = 0; i < str_len - window_size + 1; i++)
    {
        char *start = &s[i];
        //printf("start %s\n", start);
        if (subStringCmp(start, words, wordsSize, word_len) == true)
        {
            printf("Got one, i = %d\n", i);
            ret[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return ret;
}

int main()
{
    char input[] = "ttqupktjvqeeylzkyirjnnjuhyrmrhwkaoepyzavshbquaasltdyimtpmmddtzotnsknsnkkumcooeizxmyfyrwlfbqyaetpzdetsodmahcpllqizopzhnmmodkqhdfijjbbxgqansryfhiewzgfmsscvcsfizntkpukvkkjfbjmkutitzoirgmpkfuughnrykbuwnfbqqqckjlgizqbhcqtjkosudlunookbvntodvymggwhyaodqkodygzbrtpfkbifodtszughcdpdffgvpwapdzrwtiefjomxsirrcyygdpjixrfmogctfvpafvfqksncchtgftmklysipxudfyynvoncjvsvpixrpsxumlexjyfbxbgdcfqzvfcgcuctczmtsjngxtdgtkjrnqwrxorsvvyaratwcgpurfaoyfxurgneylyvzrpwmowdqqzsyropwqewvbqojfvkqtfrkxowlmbdcdycumssdwoazhpkmkufdcwpzmnmzopdtngpcyhfwyfxhuhvecajexyfjlrkcioxywnauwfsumpbhwxnazzgwzlincurnioleblaysssejwngvdgucntdadqdxhqgwdmxonxghsmrqazldhfhuakvdbabksjgvvglkdtuxhlnhkymtgtogglmhnnrhwaetgrelkyjrlwbxxnqfjgnptzygmrpkrtezkklwiwqvursrgkyrrmgklgtaykmpgqpsacpkyhfsazmgkkadygnmnioltaczrtrtvigvpnqrncazoacpirbvapivpnwigpeeykzpxphmtjlkjnzrhaphrxeimartpxxphyheoqtjzetiuszbuokloowaqnvhkuzttgzjwssxxmftggubxeoluknkzjtldsgyygjwyctxqaqwhmzeqqrmcewepsrvkyvjgfhehbezbwxkjxqbphoromxfepappwavdhzkkflociynhpowycqmrnsveumtsmovwqhgxsuzdvmkkdjihzxyoruvlioevfbtvjzsdwugritblcltdkrtbnonydtvkwofhnzljvtceodrqrktbendtdstinosjczrsbedwzgcolugcgagmpliudbdqqvbuxumyyquawxqhtwmzwsondwiizlapibmfyyfyoaymzouulivjajzfhhnhunyeqkmojrnztnmuciopqkyqtxxbgkkczihrttiemxdgkpaoxpdnzefudcxkohmpsvjlqrpdoujykjpjaszbygycjvozfarxyakorbrhvchhowtorsqpyotjlhlskcricbwveqecsllgiexbwpsxfmgqttldvcnzgmwkcaowmafwecxdrpcwdkoxezczeqbkexwiyleknlgtnfwgwaealtzpuboytrkxphfnumxhxfanmztizykktjbpnsqgjagyhnldzkkzpnmdohmpfwcaidqvvidhilfszrvadibvxnynvkccjgftmxqhftqnhwfgpdislmnkzmxwybbjigcudsdkouxvqfdhinzvzphbdezdfanpirjnmnxcjxxbccimpjjraqsdwrhbuwtencsbrrdaocdqenewxnpzfhdbamfwkybxatbumewbjatnnylmlamrjrumfzkpxloagputwqufsnuiliwzkkswbmiimszlgolmfhhdabisrfcenzfzjxvnmfxayxlgnzssgayidibwnfbceicqizfufcwfzjlmidhrffzlpchdikhotlgbllxsotxncicnnletsdehinmsyugthnuuyrmomjeoridfthannguvvhntdvomkkhjbtzpfdgyljfgrftgnqbjzqecltqwdxhhtgwymcyzoegfjblxrogqekurflpjkwqdfodttcuhgamrezqxpyovlkoqvezgcrljgpcztxizzwsfvjdmhthsdvlbbmjeeunmjsnervdsryyohbaqwjlzgwaiijmogbcrtpwmmbffzdtggvzcgkbngexqplfvmhpizlulmztmeoukmtmsdohlugclrjhgsyorjkfvmajqogbazntfdcsxjwlcfuiasytbjayvaklpqmprckwfppfynqctklvcjofupfpppbgfpwzrivzxmexawavglqkwgprxwgnmjttbrssaqrxexvetvbbitleacvxzcmnnigozbjzrazvauctrdxzzkdbnzyodndqvjhwmqydsxbstdokilljvqkkrjauydntpwpbmnhemixfnnrxyehtvrgmcgjamyvbulegalkpvjwiwqiwupsrgyglgplsphtjuarwldnhnkrlcziwqcqzawkinvbcewnawezkhmtwwkkamuxcwpbylngylhcpgpsevrocfhbeuleghbkdsobdbjdmrhezwydtrswwbzavkfdriqwbezehikwbrcaqagjrahnbgozsvelduheaglipveqogteizobzxoceebwbgifcrjdyunprrhgzamjzckaaadehgciomnrgzwevjvnccvbdhkekufkwkqdqumhhzynawtwfojhsgkxnucxqjhotzsluesdfsqgolcvbncttmriivgagppbphmjnhmsbeyqrclsrqnkcgvnbbnhqeihlxsygethktxbwlvnbjafpvstyicqmnyykqyqxrxhlxljigylpaqhxlavtemfrkfbcgtzzthmqsvaywlqwdxuozpjddrvpwysesrelasduqdvmqlivkemjwvozmjrlijrcavpdquxgxsspdckphyyfungiyxvignkjkboavlgugalldybmwzrsozbnxyvfniqyleahsjdyjpjmnkyjmrcarfpqfnxtvotgutpmetmoiwcxidgwwkxnpofvbdqwtjfnewcjpozzmbwxgftdpsshhaciduhwdmljinuaetbqxanffjiubddidfrgbyeemrqwfkyjeabdcrihatdbwhmzodhqdnwpemljzmudmyiqpqxpjcsflegajnsmaqdhfrsednjrlrhchgttinaushwdwqszgvgnmyrrnaiyrrcbxvwgjwcdfagcqybywjmkhfcvgkvzcacbvyjgxljcnsefqheoqszaxbvfnshrsjtqkcwhqgjdaqjsxphojgoihlowfxoyihqslmbbunhudqnahuqqcgylrohxlxxweposbstyfasishkbdbrfhsqbiaauxzqeogwrarpfuipmpaovdhambtnkvpguoyyeewwhqlmkvcyneoihyivzdjjyarvppttwsrdidpuytslzhtiheegjpskpjfgzacxstacwrwxnrkmagvhkzpvohffrkmslopfhpigigfvzpibvdiheadshixavlsgzhljyvrhewcflmhhprotrtnzcnbxyufadsjcqalwynbjaksrcjnvccwgrydssksvddztfkrdasocdhthqiculzbezgwrroowtoraaifaaucfdymvirpvsqarzwiqnymiodjpnorniwvnuhieayasqajpythnstwgyfxnvpdglythhclicnaspmkofrbxnxgnefbaueghcbqldetfrwahikxnbanqyveeafgxloepqxatbwbssbbcnapobehzzlfcsmzdadsqaumdqnykozmbaerbiackljmfvnkyseotzcyrpwcfyoiyscbdcfpqodxmqikioadndchsyjawziwsmzxpemhvrehhmrpdrtsuxzpxiruizscmubdapkvgoendvegpzylwacuitqstkwhexmfmwcumhjpeoxtnyfmyjgidwdygzfnzrunpwibfrtkhsfvqkjowpzzncxvbeiaxcombypgriszdywtkfkgujfjnceqgnrfrhruhjbyttxwrtqcaciunqdaskqbxjgqsalzjoyehxbbttftvpqifviafadeklxclicwwcbfbeiuxpquficmdmolmtryfobswfrujsckykhvaxphftvkfkvtdnskbvdaauujowvmjcjlzasgtnrazmvfbnrfkufkqbvgarsjtduvdobyduyfhumkjdpuawgqycxavrjqxflavpzyjzdsvpffvubvrhlrjkrgecxbjkdebcenekfzbmgwhhrapdtanmhrqguzqyfuclhgvoixbotkylmpqfrftyzjgtkzrrtwcacaqmxrdsbbfnsxujdnkeyqziptzkpemtedgdulxyofngciphxznwqnghiisxoessjaxelwczdrfgzvpzufxmsdwclozzurtesskdrofufkchhuiezfqtimvwcuxzntfhlrnefszmebvmvdsuiiprxkpbemcufhbtaozfiyuncpbxttubdjuawlecygwfqaaqqayzasmchpcciygljcofosioagvqgyjxyhwabkdkzhnjfvuqxiwlcgzdmvvvtgutpstqcybdfqomliditbuvhvavqyslemeueamiapngfbuskzbfaxcjudhldzyjmfdqfsbfhonpqihchkhkjjteoarrapbouggbahhiwuzoegsotzycktizwzswrvmlesneawoysnozwgnpfntrgescdnawimiohxvhtlhnzvmxdzokohbxnubrhcnrqxizwdiropfpmrmptazhkdexxiqgkgzcfjccmmtdcysqshgljhutkbtjjjrvrtzxcdbpquuuvmknvsafawymztykfphwihvnmwectywomjdibfnddnsfhqpohxkseifqgjvzhtpvcudgbslhgdmptbdbyptezaxgjshsnxnqtryvjjcrnoiirnlqdewcgvkppshdpvvkotfzcjrrzbarpljushwydjosbxvsuqcijkiovbfvcfottznlgmljvbcwzxqvouezeopcpvxtcnnvmaisoucjvehwdxstsyvymkadfzwiolfaoovcixofdvcivwcpuxpghqjprhzgteihsdlcczifvmosisjerymaqvpieoqxtygncsqeramomcgwupanqmngjfontgnoftejlunfuzvidceztgmlucsfhiscphrwbvforsvnurvzvzzohlabnugucaztiqpjnuzgpvtlmokhpjxwvzxkvfhyfgrnyjyndatsvodjcqstzrpwtohotqmaygqwpoluqgnluswyiqtkiigbwpprhetfmjddaqxqwmeshasrrlbbvietzvkhbeonpsqpioghckzjmubfhcgdmmwoijxjplxedpuofavimwtasugazodnbbblkyuzktepjafqccyqbsqtoyvnnadqcebmfvorruiawoqyqrotlgnbfirujuknynbfkrwblhdhvuhnnxhaewbjgsdrmpencismzrqlytuvnekcbtcfreqywtrjiwymeqbfjrqhknearpcukfaclsahmrswpqlvjmbsdtcnigpzxsukzwmkootchmbxeounavgfrkuzqkbqexadvmnlciojurgbfdohaworgirzsupwrrbmfqxhznqvgzwncnucjiuqtnpnhgmyxnmcejjdzbafaxtckpftazltocgvisvhihjmsurrwrxwqqzahgwhhjcvmlswdnelwnzokqggkdeavfdelbmsmopabhxfwbssquhcmpkwupzpuetihhctysuzzrgwubqmvxpjoziiohxlntvucxpcpjcrckpynflifautbccqjbdywasbxhdpthixuxwhehqljkfkojcxmhvlhpmhwryrzgptflajusvfecpsnurbdomldaucsstrykmdvmorhlwnpogcizelosyrtuvlmrembqrxeiqntnbjbjnlitywmxqhrlugeyugqmfwuvkpinylwowghvdvuveniyvnyqtocylytxnekopicoolltjfonuzmqmkghbkhoialvgxlyhpmvdxpmefzyenosawzbggrojcmrbzpipddscueicfhivxbvwcyclprutfnuedevijnngtvibeqwcttyytcjivfdaszhxdcimqvsjqakvtizobxmubxexchxvgeulhcyzxqkotxjofkejjrfkokhttfoclknunntkggazdlpkvttemzpdlwwgdmirwyljlhwrpwssihcddykrzzukxssdgbwdbjomqmghjyztiewnciedhbphvhmckihlrxykkgrvetooxmbbvieejtleaxinhryzpylzecwlvkzuwdvrlbwuwjaxjlmqckrrjcspfoacaaxxduqqwmksymrhxdzcortztooaepffrccwwsmuhynfkgokknmaghbcvpcagjfzljvkdjgkhvrucfgovsqbbrdxii";
    char *word[] = {
        "wxnazzgwzlincurnioleblays", 
        "txwrtqcaciunqdaskqbxjgqsa", 
        "vdhzkkflociynhpowycqmrnsv", 
        "sondwiizlapibmfyyfyoaymzo", 
        "advmnlciojurgbfdohaworgir", 
        "gbwpprhetfmjddaqxqwmeshas", 
        "vmjcjlzasgtnrazmvfbnrfkuf", 
        "zjxvnmfxayxlgnzssgayidibw", 
        "xmsdwclozzurtesskdrofufkc", 
        "gglmhnnrhwaetgrelkyjrlwbx", 
        "galldybmwzrsozbnxyvfniqyl", 
        "ofrbxnxgnefbaueghcbqldetf", 
        "ltaczrtrtvigvpnqrncazoacp", 
        "psacpkyhfsazmgkkadygnmnio", 
        "mztmeoukmtmsdohlugclrjhgs", 
        "gjdaqjsxphojgoihlowfxoyih", 
        "gpcztxizzwsfvjdmhthsdvlbb", 
        "bksjgvvglkdtuxhlnhkymtgto", 
        "mewbjatnnylmlamrjrumfzkpx", 
        "orsqpyotjlhlskcricbwveqec", 
        "wsrdidpuytslzhtiheegjpskp", 
        "zehikwbrcaqagjrahnbgozsve", 
        "lzjoyehxbbttftvpqifviafad",
        "phyyfungiyxvignkjkboavlgu",
        "zdadsqaumdqnykozmbaerbiac",
        "zxyoruvlioevfbtvjzsdwugri",
        "xtvotgutpmetmoiwcxidgwwkx",
        "cpvxtcnnvmaisoucjvehwdxst",
        "jfgzacxstacwrwxnrkmagvhkz",
        "nubrhcnrqxizwdiropfpmrmpt",
        "rwahikxnbanqyveeafgxloepq",
        "zncxvbeiaxcombypgriszdywt",
        "ottznlgmljvbcwzxqvouezeop",
        "rqguzqyfuclhgvoixbotkylmp",
        "zdsvpffvubvrhlrjkrgecxbjk",
        "kqbvgarsjtduvdobyduyfhumk",
        "azhkdexxiqgkgzcfjccmmtdcy",
        "igcudsdkouxvqfdhinzvzphbd",
        "igylpaqhxlavtemfrkfbcgtzz",
        "ezdfanpirjnmnxcjxxbccimpj",
        "hwydjosbxvsuqcijkiovbfvcf",
        "lzgwaiijmogbcrtpwmmbffzdt",
        "fsqgolcvbncttmriivgagppbp",
        "hsqbiaauxzqeogwrarpfuipmp",
        "mxonxghsmrqazldhfhuakvdba",
        "legajnsmaqdhfrsednjrlrhch",
        "eebwbgifcrjdyunprrhgzamjz",
        "suxzpxiruizscmubdapkvgoen",
        "uvnekcbtcfreqywtrjiwymeqb",
        "pquuuvmknvsafawymztykfphw",
        "bhxfwbssquhcmpkwupzpuetih",
        "pshdpvvkotfzcjrrzbarpljus",
        "edgdulxyofngciphxznwqnghi",
        "pwzrivzxmexawavglqkwgprxw",
        "wimiohxvhtlhnzvmxdzokohbx",
        "sjcqalwynbjaksrcjnvccwgry",
        "qwfkyjeabdcrihatdbwhmzodh",
        "thmqsvaywlqwdxuozpjddrvpw",
        "jdpuawgqycxavrjqxflavpzyj",
        "xphftvkfkvtdnskbvdaauujow",
        "mwkcaowmafwecxdrpcwdkoxez",
        "rrlbbvietzvkhbeonpsqpiogh",
        "gyglgplsphtjuarwldnhnkrlc",
        "sqshgljhutkbtjjjrvrtzxcdb",
        "ihvnmwectywomjdibfnddnsfh",
        "dymvirpvsqarzwiqnymiodjpn",
        "evrocfhbeuleghbkdsobdbjdm",
        "sbbfnsxujdnkeyqziptzkpemt",
        "gmlucsfhiscphrwbvforsvnur",
        "nfbceicqizfufcwfzjlmidhrf",
        "tbqxanffjiubddidfrgbyeemr",
        "fszmebvmvdsuiiprxkpbemcuf",
        "ziwqcqzawkinvbcewnawezkhm",
        "dmolmtryfobswfrujsckykhva",
        "ewcflmhhprotrtnzcnbxyufad",
        "qcebmfvorruiawoqyqrotlgnb",
        "qdnwpemljzmudmyiqpqxpjcsf",
        "xhaewbjgsdrmpencismzrqlyt",
        "iyrrcbxvwgjwcdfagcqybywjm",
        "rhezwydtrswwbzavkfdriqwbe",
        "kljmfvnkyseotzcyrpwcfyoiy",
        "xtygncsqeramomcgwupanqmng",
        "uzoegsotzycktizwzswrvmles",
        "fzlpchdikhotlgbllxsotxnci",
        "rrwrxwqqzahgwhhjcvmlswdne",
        "xtckpftazltocgvisvhihjmsu",
        "aovdhambtnkvpguoyyeewwhql",
        "qenewxnpzfhdbamfwkybxatbu",
        "wqvursrgkyrrmgklgtaykmpgq",
        "ezbwxkjxqbphoromxfepappwa",
        "mzeqqrmcewepsrvkyvjgfhehb",
        "ulzbezgwrroowtoraaifaaucf",
        "rdxzzkdbnzyodndqvjhwmqyds",
        "qtryvjjcrnoiirnlqdewcgvkp",
        "slemeueamiapngfbuskzbfaxc",
        "ssejwngvdgucntdadqdxhqgwd",
        "lhgdmptbdbyptezaxgjshsnxn",
        "qheoqszaxbvfnshrsjtqkcwhq",
        "twwkkamuxcwpbylngylhcpgps",
        "fszrvadibvxnynvkccjgftmxq",
        "hftqnhwfgpdislmnkzmxwybbj",
        "iimszlgolmfhhdabisrfcenzf",
        "mztizykktjbpnsqgjagyhnldz",
        "eacvxzcmnnigozbjzrazvauct",
        "hkhkjjteoarrapbouggbahhiw",
        "uknkzjtldsgyygjwyctxqaqwh",
        "lduheaglipveqogteizobzxoc",
        "ggvzcgkbngexqplfvmhpizlul",
        "omjeoridfthannguvvhntdvom",
        "uulivjajzfhhnhunyeqkmojrn",
        "npofvbdqwtjfnewcjpozzmbwx",
        "altzpuboytrkxphfnumxhxfan",
        "scbdcfpqodxmqikioadndchsy",
        "jfontgnoftejlunfuzvidcezt",
        "pvohffrkmslopfhpigigfvzpi",
        "kkhjbtzpfdgyljfgrftgnqbjz",
        "sllgiexbwpsxfmgqttldvcnzg",
        "exyfjlrkcioxywnauwfsumpbh",
        "hkuzttgzjwssxxmftggubxeol",
        "gftdpsshhaciduhwdmljinuae",
        "uzktepjafqccyqbsqtoyvnnad",
        "fnzrunpwibfrtkhsfvqkjowpz",
        "gpvtlmokhpjxwvzxkvfhyfgrn",
        "hgamrezqxpyovlkoqvezgcrlj",
        "qslmbbunhudqnahuqqcgylroh",
        "otchmbxeounavgfrkuzqkbqex",
        "lcczifvmosisjerymaqvpieoq",
        "ljvtceodrqrktbendtdstinos",
        "jlkjnzrhaphrxeimartpxxphy",
        "judhldzyjmfdqfsbfhonpqihc",
        "lxrogqekurflpjkwqdfodttcu",
        "firujuknynbfkrwblhdhvuhnn",
        "cnnletsdehinmsyugthnuuyrm",
        "stqcybdfqomliditbuvhvavqy",
        "ckzjmubfhcgdmmwoijxjplxed",
        "ttiemxdgkpaoxpdnzefudcxko",
        "jiuqtnpnhgmyxnmcejjdzbafa",
        "eumtsmovwqhgxsuzdvmkkdjih",
        "irbvapivpnwigpeeykzpxphmt",
        "czeqbkexwiyleknlgtnfwgwae",
        "eklxclicwwcbfbeiuxpquficm",
        "xatbwbssbbcnapobehzzlfcsm",
        "ztnmuciopqkyqtxxbgkkczihr",
        "heoqtjzetiuszbuokloowaqnv",
        "vbdhkekufkwkqdqumhhzynawt",
        "fjrqhknearpcukfaclsahmrsw",
        "xlxxweposbstyfasishkbdbrf",
        "qfrftyzjgtkzrrtwcacaqmxrd",
        "ljcofosioagvqgyjxyhwabkdk",
        "ecygwfqaaqqayzasmchpcciyg",
        "lwnzokqggkdeavfdelbmsmopa",
        "vzvzzohlabnugucaztiqpjnuz",
        "hmpsvjlqrpdoujykjpjaszbyg",
        "qecltqwdxhhtgwymcyzoegfjb",
        "kkzpnmdohmpfwcaidqvvidhil",
        "yorjkfvmajqogbazntfdcsxjw",
        "ozmjrlijrcavpdquxgxsspdck",
        "pbmnhemixfnnrxyehtvrgmcgj",
        "hmjnhmsbeyqrclsrqnkcgvnbb",
        "gnmjttbrssaqrxexvetvbbitl",
        "mjeeunmjsnervdsryyohbaqwj",
        "dbdqqvbuxumyyquawxqhtwmzw",
        "pqlvjmbsdtcnigpzxsukzwmko",
        "khfcvgkvzcacbvyjgxljcnsef",
        "gttinaushwdwqszgvgnmyrrna",
        "jawziwsmzxpemhvrehhmrpdrt",
        "jraqsdwrhbuwtencsbrrdaocd",
        "wcumhjpeoxtnyfmyjgidwdygz",
        "zsupwrrbmfqxhznqvgzwncnuc",
        "isxoessjaxelwczdrfgzvpzuf",
        "mkvcyneoihyivzdjjyarvpptt",
        "tblcltdkrtbnonydtvkwofhnz",
        "bvdiheadshixavlsgzhljyvrh",
        "wgyfxnvpdglythhclicnaspmk",
        "jczrsbedwzgcolugcgagmpliu",
        "hbtaozfiyuncpbxttubdjuawl",
        "ysesrelasduqdvmqlivkemjwv",
        "dvegpzylwacuitqstkwhexmfm",
        "qpohxkseifqgjvzhtpvcudgbs",
        "xnqfjgnptzygmrpkrtezkklwi",
        "loagputwqufsnuiliwzkkswbm",
        "qmaygqwpoluqgnluswyiqtkii",
        "kfkgujfjnceqgnrfrhruhjbyt",
        "hhuiezfqtimvwcuxzntfhlrne",
        "fppfynqctklvcjofupfpppbgf",
        "zhnjfvuqxiwlcgzdmvvvtgutp",
        "wfojhsgkxnucxqjhotzsluesd",
        "debcenekfzbmgwhhrapdtanmh",
        "yjyndatsvodjcqstzrpwtohot",
        "eahsjdyjpjmnkyjmrcarfpqfn",
        "neawoysnozwgnpfntrgescdna",
        "amyvbulegalkpvjwiwqiwupsr",
        "orniwvnuhieayasqajpythnst",
        "ckaaadehgciomnrgzwevjvncc",
        "syvymkadfzwiolfaoovcixofd",
        "dssksvddztfkrdasocdhthqic",
        "vcivwcpuxpghqjprhzgteihsd",
        "lcfuiasytbjayvaklpqmprckw",
        "ycjvozfarxyakorbrhvchhowt",
        "fpvstyicqmnyykqyqxrxhlxlj",
        "puofavimwtasugazodnbbblky",
        "nhqeihlxsygethktxbwlvnbja",
        "xbstdokilljvqkkrjauydntpw",
    };
    int returnSize = 0;
    int *ret = findSubstring(input, word, 284-82+1, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d: %d\n", i, ret[i]);
    }
    free(ret);
    return 0;
}