int msga[321][30];
char msgi[321][3];

void init_msgi(){

msga['A']['A']=	0;
msga['A']['B']=	1;
msga['A']['C']=	2;
msga['A']['D']=	3;
msga['A']['E']=	4;
msga['A']['F']=	5;
msga['A']['G']=	6;
msga['A']['H']=	7;
msga['A']['I']=	8;
msga['A']['J']=	9;
msga['A']['K']=	10;
msga['A']['L']=	11;
msga['A']['M']=	12;
msga['A']['N']=	13;
msga['A']['O']=	14;
msga['A']['P']=	15;
msga['A']['Q']=	16;
msga['A']['R']=	17;
msga['A']['S']=	18;
msga['A']['T']=	19;
msga['A']['U']=	20;
msga['A']['V']=	21;
msga['A']['W']=	22;
msga['A']['X']=	23;
msga['A']['Y']=	24;
msga['A']['Z']=	25;
msga['B']['A']=	26;
msga['B']['B']=	27;
msga['B']['C']=	28;
msga['B']['D']=	29;
msga['B']['E']=	30;
msga['B']['F']=	31;
msga['B']['G']=	32;
msga['B']['H']=	33;
msga['B']['I']=	34;
msga['B']['J']=	35;
msga['B']['K']=	36;
msga['B']['L']=	37;
msga['B']['M']=	38;
msga['B']['N']=	39;
msga['B']['O']=	40;
msga['B']['P']=	41;
msga['B']['Q']=	42;
msga['B']['R']=	43;
msga['B']['S']=	44;
msga['B']['T']=	45;
msga['B']['U']=	46;
msga['B']['V']=	47;
msga['B']['W']=	48;
msga['B']['X']=	49;
msga['B']['Y']=	50;
msga['B']['Z']=	51;
msga['C']['A']=	52;
msga['C']['B']=	53;
msga['C']['C']=	54;
msga['C']['D']=	55;
msga['C']['E']=	56;
msga['C']['F']=	57;
msga['C']['G']=	58;
msga['C']['H']=	59;
msga['C']['I']=	60;
msga['C']['J']=	61;
msga['C']['K']=	62;
msga['C']['L']=	63;
msga['C']['M']=	64;
msga['C']['N']=	65;
msga['C']['O']=	66;
msga['C']['P']=	67;
msga['C']['Q']=	68;
msga['C']['R']=	69;
msga['C']['S']=	70;
msga['C']['T']=	71;
msga['C']['U']=	72;
msga['C']['V']=	73;
msga['C']['W']=	74;
msga['C']['X']=	75;
msga['C']['Y']=	76;
msga['C']['Z']=	77;
msga['D']['A']=	78;
msga['D']['B']=	79;
msga['D']['C']=	80;
msga['D']['D']=	81;
msga['D']['E']=	82;
msga['D']['F']=	83;
msga['D']['G']=	84;
msga['D']['H']=	85;
msga['D']['I']=	86;
msga['D']['J']=	87;
msga['D']['K']=	88;
msga['D']['L']=	89;
msga['D']['M']=	90;
msga['D']['N']=	91;
msga['D']['O']=	92;
msga['D']['P']=	93;
msga['D']['Q']=	94;
msga['D']['R']=	95;
msga['D']['S']=	96;
msga['D']['T']=	97;
msga['D']['U']=	98;
msga['D']['V']=	99;
msga['D']['W']=	100;
msga['D']['X']=	101;
msga['D']['Y']=	102;
msga['D']['Z']=	103;
msga['E']['A']=	104;
msga['E']['B']=	105;
msga['E']['C']=	106;
msga['E']['D']=	107;
msga['E']['E']=	108;
msga['E']['F']=	109;
msga['E']['G']=	110;
msga['E']['H']=	111;
msga['E']['I']=	112;
msga['E']['J']=	113;
msga['E']['K']=	114;
msga['E']['L']=	115;
msga['E']['M']=	116;
msga['E']['N']=	117;
msga['E']['O']=	118;
msga['E']['P']=	119;
msga['E']['Q']=	120;
msga['E']['R']=	121;
msga['E']['S']=	122;
msga['E']['T']=	123;
msga['E']['U']=	124;
msga['E']['V']=	125;
msga['E']['W']=	126;
msga['E']['X']=	127;
msga['E']['Y']=	128;
msga['E']['Z']=	129;
msga['F']['A']=	130;
msga['F']['B']=	131;
msga['F']['C']=	132;
msga['F']['D']=	133;
msga['F']['E']=	134;
msga['F']['F']=	135;
msga['F']['G']=	136;
msga['F']['H']=	137;
msga['F']['I']=	138;
msga['F']['J']=	139;
msga['F']['K']=	140;
msga['F']['L']=	141;
msga['F']['M']=	142;
msga['F']['N']=	143;
msga['F']['O']=	144;
msga['F']['P']=	145;
msga['F']['Q']=	146;
msga['F']['R']=	147;
msga['F']['S']=	148;
msga['F']['T']=	149;
msga['F']['U']=	150;
msga['F']['V']=	151;
msga['F']['W']=	152;
msga['F']['X']=	153;
msga['F']['Y']=	154;
msga['F']['Z']=	155;
msga['G']['A']=	156;
msga['G']['B']=	157;
msga['G']['C']=	158;
msga['G']['D']=	159;
msga['G']['E']=	160;
msga['G']['F']=	161;
msga['G']['G']=	162;
msga['G']['H']=	163;
msga['G']['I']=	164;
msga['G']['J']=	165;
msga['G']['K']=	166;
msga['G']['L']=	167;
msga['G']['M']=	168;
msga['G']['N']=	169;
msga['G']['O']=	170;
msga['G']['P']=	171;
msga['G']['Q']=	172;
msga['G']['R']=	173;
msga['G']['S']=	174;
msga['G']['T']=	175;
msga['G']['U']=	176;
msga['G']['V']=	177;
msga['G']['W']=	178;
msga['G']['X']=	179;
msga['G']['Y']=	180;
msga['G']['Z']=	181;
msga['H']['A']=	182;
msga['H']['B']=	183;
msga['H']['C']=	184;
msga['H']['D']=	185;
msga['H']['E']=	186;
msga['H']['F']=	187;
msga['H']['G']=	188;
msga['H']['H']=	189;
msga['H']['I']=	190;
msga['H']['J']=	191;
msga['H']['K']=	192;
msga['H']['L']=	193;
msga['H']['M']=	194;
msga['H']['N']=	195;
msga['H']['O']=	196;
msga['H']['P']=	197;
msga['H']['Q']=	198;
msga['H']['R']=	199;
msga['H']['S']=	200;
msga['H']['T']=	201;
msga['H']['U']=	202;
msga['H']['V']=	203;
msga['H']['W']=	204;
msga['H']['X']=	205;
msga['H']['Y']=	206;
msga['H']['Z']=	207;
msga['I']['A']=	208;
msga['I']['B']=	209;
msga['I']['C']=	210;
msga['I']['D']=	211;
msga['I']['E']=	212;
msga['I']['F']=	213;
msga['I']['G']=	214;
msga['I']['H']=	215;
msga['I']['I']=	216;
msga['I']['J']=	217;
msga['I']['K']=	218;
msga['I']['L']=	219;
msga['I']['M']=	220;
msga['I']['N']=	221;
msga['I']['O']=	222;
msga['I']['P']=	223;
msga['I']['Q']=	224;
msga['I']['R']=	225;
msga['I']['S']=	226;
msga['I']['T']=	227;
msga['I']['U']=	228;
msga['I']['V']=	229;
msga['I']['W']=	230;
msga['I']['X']=	231;
msga['I']['Y']=	232;
msga['I']['Z']=	233;
msga['J']['A']=	234;
msga['J']['B']=	235;
msga['J']['C']=	236;
msga['J']['D']=	237;
msga['J']['E']=	238;
msga['J']['F']=	239;
msga['J']['G']=	240;
msga['J']['H']=	241;
msga['J']['I']=	242;
msga['J']['J']=	243;
msga['J']['K']=	244;
msga['J']['L']=	245;
msga['J']['M']=	246;
msga['J']['N']=	247;
msga['J']['O']=	248;
msga['J']['P']=	249;
msga['J']['Q']=	250;
msga['J']['R']=	251;
msga['J']['S']=	252;
msga['J']['T']=	253;
msga['J']['U']=	254;
msga['J']['V']=	255;
msga['J']['W']=	256;
msga['J']['X']=	257;
msga['J']['Y']=	258;
msga['J']['Z']=	259;
msga['K']['A']=	260;
msga['K']['B']=	261;
msga['K']['C']=	262;
msga['K']['D']=	263;
msga['K']['E']=	264;
msga['K']['F']=	265;
msga['K']['G']=	266;
msga['K']['H']=	267;
msga['K']['I']=	268;
msga['K']['J']=	269;
msga['K']['K']=	270;
msga['K']['L']=	271;
msga['K']['M']=	272;
msga['K']['N']=	273;
msga['K']['O']=	274;
msga['K']['P']=	275;
msga['K']['Q']=	276;
msga['K']['R']=	277;
msga['K']['S']=	278;
msga['K']['T']=	279;
msga['K']['U']=	280;
msga['K']['V']=	281;
msga['K']['W']=	282;
msga['K']['X']=	283;
msga['K']['Y']=	284;
msga['K']['Z']=	285;
msga['L']['A']=	286;
msga['L']['B']=	287;
msga['L']['C']=	288;
msga['L']['D']=	289;
msga['L']['E']=	290;
msga['L']['F']=	291;
msga['L']['G']=	292;
msga['L']['H']=	293;
msga['L']['I']=	294;
msga['L']['J']=	295;
msga['L']['K']=	296;
msga['L']['L']=	297;
msga['L']['M']=	298;
msga['L']['N']=	299;
msga['L']['O']=	300;
msga['L']['P']=	301;
msga['L']['Q']=	302;
msga['L']['R']=	303;
msga['L']['S']=	304;
msga['L']['T']=	305;
msga['L']['U']=	306;
msga['L']['V']=	307;
msga['L']['W']=	308;
msga['L']['X']=	309;
msga['L']['Y']=	310;
msga['L']['Z']=	311;
msga['M']['A']=	312;
msga['M']['B']=	313;
msga['M']['C']=	314;
msga['M']['D']=	315;
msga['M']['E']=	316;
msga['M']['F']=	317;
msga['M']['G']=	318;
msga['M']['H']=	319;
msga['M']['I']=	320;


strcpy(msgi[0],"AA");
strcpy(msgi[1],"AB");
strcpy(msgi[2],"AC");
strcpy(msgi[3],"AD");
strcpy(msgi[4],"AE");
strcpy(msgi[5],"AF");
strcpy(msgi[6],"AG");
strcpy(msgi[7],"AH");
strcpy(msgi[8],"AI");
strcpy(msgi[9],"AJ");
strcpy(msgi[10],"AK");
strcpy(msgi[11],"AL");
strcpy(msgi[12],"AM");
strcpy(msgi[13],"AN");
strcpy(msgi[14],"AO");
strcpy(msgi[15],"AP");
strcpy(msgi[16],"AQ");
strcpy(msgi[17],"AR");
strcpy(msgi[18],"AS");
strcpy(msgi[19],"AT");
strcpy(msgi[20],"AU");
strcpy(msgi[21],"AV");
strcpy(msgi[22],"AW");
strcpy(msgi[23],"AX");
strcpy(msgi[24],"AY");
strcpy(msgi[25],"AZ");
strcpy(msgi[26],"BA");
strcpy(msgi[27],"BB");
strcpy(msgi[28],"BC");
strcpy(msgi[29],"BD");
strcpy(msgi[30],"BE");
strcpy(msgi[31],"BF");
strcpy(msgi[32],"BG");
strcpy(msgi[33],"BH");
strcpy(msgi[34],"BI");
strcpy(msgi[35],"BJ");
strcpy(msgi[36],"BK");
strcpy(msgi[37],"BL");
strcpy(msgi[38],"BM");
strcpy(msgi[39],"BN");
strcpy(msgi[40],"BO");
strcpy(msgi[41],"BP");
strcpy(msgi[42],"BQ");
strcpy(msgi[43],"BR");
strcpy(msgi[44],"BS");
strcpy(msgi[45],"BT");
strcpy(msgi[46],"BU");
strcpy(msgi[47],"BV");
strcpy(msgi[48],"BW");
strcpy(msgi[49],"BX");
strcpy(msgi[50],"BY");
strcpy(msgi[51],"BZ");
strcpy(msgi[52],"CA");
strcpy(msgi[53],"CB");
strcpy(msgi[54],"CC");
strcpy(msgi[55],"CD");
strcpy(msgi[56],"CE");
strcpy(msgi[57],"CF");
strcpy(msgi[58],"CG");
strcpy(msgi[59],"CH");
strcpy(msgi[60],"CI");
strcpy(msgi[61],"CJ");
strcpy(msgi[62],"CK");
strcpy(msgi[63],"CL");
strcpy(msgi[64],"CM");
strcpy(msgi[65],"CN");
strcpy(msgi[66],"CO");
strcpy(msgi[67],"CP");
strcpy(msgi[68],"CQ");
strcpy(msgi[69],"CR");
strcpy(msgi[70],"CS");
strcpy(msgi[71],"CT");
strcpy(msgi[72],"CU");
strcpy(msgi[73],"CV");
strcpy(msgi[74],"CW");
strcpy(msgi[75],"CX");
strcpy(msgi[76],"CY");
strcpy(msgi[77],"CZ");
strcpy(msgi[78],"DA");
strcpy(msgi[79],"DB");
strcpy(msgi[80],"DC");
strcpy(msgi[81],"DD");
strcpy(msgi[82],"DE");
strcpy(msgi[83],"DF");
strcpy(msgi[84],"DG");
strcpy(msgi[85],"DH");
strcpy(msgi[86],"DI");
strcpy(msgi[87],"DJ");
strcpy(msgi[88],"DK");
strcpy(msgi[89],"DL");
strcpy(msgi[90],"DM");
strcpy(msgi[91],"DN");
strcpy(msgi[92],"DO");
strcpy(msgi[93],"DP");
strcpy(msgi[94],"DQ");
strcpy(msgi[95],"DR");
strcpy(msgi[96],"DS");
strcpy(msgi[97],"DT");
strcpy(msgi[98],"DU");
strcpy(msgi[99],"DV");
strcpy(msgi[100],"DW");
strcpy(msgi[101],"DX");
strcpy(msgi[102],"DY");
strcpy(msgi[103],"DZ");
strcpy(msgi[104],"EA");
strcpy(msgi[105],"EB");
strcpy(msgi[106],"EC");
strcpy(msgi[107],"ED");
strcpy(msgi[108],"EE");
strcpy(msgi[109],"EF");
strcpy(msgi[110],"EG");
strcpy(msgi[111],"EH");
strcpy(msgi[112],"EI");
strcpy(msgi[113],"EJ");
strcpy(msgi[114],"EK");
strcpy(msgi[115],"EL");
strcpy(msgi[116],"EM");
strcpy(msgi[117],"EN");
strcpy(msgi[118],"EO");
strcpy(msgi[119],"EP");
strcpy(msgi[120],"EQ");
strcpy(msgi[121],"ER");
strcpy(msgi[122],"ES");
strcpy(msgi[123],"ET");
strcpy(msgi[124],"EU");
strcpy(msgi[125],"EV");
strcpy(msgi[126],"EW");
strcpy(msgi[127],"EX");
strcpy(msgi[128],"EY");
strcpy(msgi[129],"EZ");
strcpy(msgi[130],"FA");
strcpy(msgi[131],"FB");
strcpy(msgi[132],"FC");
strcpy(msgi[133],"FD");
strcpy(msgi[134],"FE");
strcpy(msgi[135],"FF");
strcpy(msgi[136],"FG");
strcpy(msgi[137],"FH");
strcpy(msgi[138],"FI");
strcpy(msgi[139],"FJ");
strcpy(msgi[140],"FK");
strcpy(msgi[141],"FL");
strcpy(msgi[142],"FM");
strcpy(msgi[143],"FN");
strcpy(msgi[144],"FO");
strcpy(msgi[145],"FP");
strcpy(msgi[146],"FQ");
strcpy(msgi[147],"FR");
strcpy(msgi[148],"FS");
strcpy(msgi[149],"FT");
strcpy(msgi[150],"FU");
strcpy(msgi[151],"FV");
strcpy(msgi[152],"FW");
strcpy(msgi[153],"FX");
strcpy(msgi[154],"FY");
strcpy(msgi[155],"FZ");
strcpy(msgi[156],"GA");
strcpy(msgi[157],"GB");
strcpy(msgi[158],"GC");
strcpy(msgi[159],"GD");
strcpy(msgi[160],"GE");
strcpy(msgi[161],"GF");
strcpy(msgi[162],"GG");
strcpy(msgi[163],"GH");
strcpy(msgi[164],"GI");
strcpy(msgi[165],"GJ");
strcpy(msgi[166],"GK");
strcpy(msgi[167],"GL");
strcpy(msgi[168],"GM");
strcpy(msgi[169],"GN");
strcpy(msgi[170],"GO");
strcpy(msgi[171],"GP");
strcpy(msgi[172],"GQ");
strcpy(msgi[173],"GR");
strcpy(msgi[174],"GS");
strcpy(msgi[175],"GT");
strcpy(msgi[176],"GU");
strcpy(msgi[177],"GV");
strcpy(msgi[178],"GW");
strcpy(msgi[179],"GX");
strcpy(msgi[180],"GY");
strcpy(msgi[181],"GZ");
strcpy(msgi[182],"HA");
strcpy(msgi[183],"HB");
strcpy(msgi[184],"HC");
strcpy(msgi[185],"HD");
strcpy(msgi[186],"HE");
strcpy(msgi[187],"HF");
strcpy(msgi[188],"HG");
strcpy(msgi[189],"HH");
strcpy(msgi[190],"HI");
strcpy(msgi[191],"HJ");
strcpy(msgi[192],"HK");
strcpy(msgi[193],"HL");
strcpy(msgi[194],"HM");
strcpy(msgi[195],"HN");
strcpy(msgi[196],"HO");
strcpy(msgi[197],"HP");
strcpy(msgi[198],"HQ");
strcpy(msgi[199],"HR");
strcpy(msgi[200],"HS");
strcpy(msgi[201],"HT");
strcpy(msgi[202],"HU");
strcpy(msgi[203],"HV");
strcpy(msgi[204],"HW");
strcpy(msgi[205],"HX");
strcpy(msgi[206],"HY");
strcpy(msgi[207],"HZ");
strcpy(msgi[208],"IA");
strcpy(msgi[209],"IB");
strcpy(msgi[210],"IC");
strcpy(msgi[211],"ID");
strcpy(msgi[212],"IE");
strcpy(msgi[213],"IF");
strcpy(msgi[214],"IG");
strcpy(msgi[215],"IH");
strcpy(msgi[216],"II");
strcpy(msgi[217],"IJ");
strcpy(msgi[218],"IK");
strcpy(msgi[219],"IL");
strcpy(msgi[220],"IM");
strcpy(msgi[221],"IN");
strcpy(msgi[222],"IO");
strcpy(msgi[223],"IP");
strcpy(msgi[224],"IQ");
strcpy(msgi[225],"IR");
strcpy(msgi[226],"IS");
strcpy(msgi[227],"IT");
strcpy(msgi[228],"IU");
strcpy(msgi[229],"IV");
strcpy(msgi[230],"IW");
strcpy(msgi[231],"IX");
strcpy(msgi[232],"IY");
strcpy(msgi[233],"IZ");
strcpy(msgi[234],"JA");
strcpy(msgi[235],"JB");
strcpy(msgi[236],"JC");
strcpy(msgi[237],"JD");
strcpy(msgi[238],"JE");
strcpy(msgi[239],"JF");
strcpy(msgi[240],"JG");
strcpy(msgi[241],"JH");
strcpy(msgi[242],"JI");
strcpy(msgi[243],"JJ");
strcpy(msgi[244],"JK");
strcpy(msgi[245],"JL");
strcpy(msgi[246],"JM");
strcpy(msgi[247],"JN");
strcpy(msgi[248],"JO");
strcpy(msgi[249],"JP");
strcpy(msgi[250],"JQ");
strcpy(msgi[251],"JR");
strcpy(msgi[252],"JS");
strcpy(msgi[253],"JT");
strcpy(msgi[254],"JU");
strcpy(msgi[255],"JV");
strcpy(msgi[256],"JW");
strcpy(msgi[257],"JX");
strcpy(msgi[258],"JY");
strcpy(msgi[259],"JZ");
strcpy(msgi[260],"KA");
strcpy(msgi[261],"KB");
strcpy(msgi[262],"KC");
strcpy(msgi[263],"KD");
strcpy(msgi[264],"KE");
strcpy(msgi[265],"KF");
strcpy(msgi[266],"KG");
strcpy(msgi[267],"KH");
strcpy(msgi[268],"KI");
strcpy(msgi[269],"KJ");
strcpy(msgi[270],"KK");
strcpy(msgi[271],"KL");
strcpy(msgi[272],"KM");
strcpy(msgi[273],"KN");
strcpy(msgi[274],"KO");
strcpy(msgi[275],"KP");
strcpy(msgi[276],"KQ");
strcpy(msgi[277],"KR");
strcpy(msgi[278],"KS");
strcpy(msgi[279],"KT");
strcpy(msgi[280],"KU");
strcpy(msgi[281],"KV");
strcpy(msgi[282],"KW");
strcpy(msgi[283],"KX");
strcpy(msgi[284],"KY");
strcpy(msgi[285],"KZ");
strcpy(msgi[286],"LA");
strcpy(msgi[287],"LB");
strcpy(msgi[288],"LC");
strcpy(msgi[289],"LD");
strcpy(msgi[290],"LE");
strcpy(msgi[291],"LF");
strcpy(msgi[292],"LG");
strcpy(msgi[293],"LH");
strcpy(msgi[294],"LI");
strcpy(msgi[295],"LJ");
strcpy(msgi[296],"LK");
strcpy(msgi[297],"LL");
strcpy(msgi[298],"LM");
strcpy(msgi[299],"LN");
strcpy(msgi[300],"LO");
strcpy(msgi[301],"LP");
strcpy(msgi[302],"LQ");
strcpy(msgi[303],"LR");
strcpy(msgi[304],"LS");
strcpy(msgi[305],"LT");
strcpy(msgi[306],"LU");
strcpy(msgi[307],"LV");
strcpy(msgi[308],"LW");
strcpy(msgi[309],"LX");
strcpy(msgi[310],"LY");
strcpy(msgi[311],"LZ");
strcpy(msgi[312],"MA");
strcpy(msgi[313],"MB");
strcpy(msgi[314],"MC");
strcpy(msgi[315],"MD");
strcpy(msgi[316],"ME");
strcpy(msgi[317],"MF");
strcpy(msgi[318],"MG");
strcpy(msgi[319],"MH");
strcpy(msgi[320],"MI");

}


void print_msgi(){
	int i=0;
	for(i=0;i<=320;i++)
	printf("%s\n",msgi[i]);
}