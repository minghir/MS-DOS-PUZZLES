#include <stdio.h>
#include <dos.h>
#include <time.h>
#include <conio.h>
#include <mem.h>
#include <alloc.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>

#include "LVGA\\lvga.h"
#include "LVGA\\keyb.h"
#include "LVGA\\ini.h"
#include "LVGA\\mouse.h"

#define MAX_ZOOM 5
#define MAX_DELAY 2000
#define MAX_SIZE 250
#define MAX_CELLS MAX_SIZE*MAX_SIZE
#define KEY_DELAY 150
#define TEXT_COLOR 42
#define TEXT_COLOR2 43
#define BORDER_COLOR 26

int zoom = 5;
float a_ratio = 1.2;

word tstart,tend, fps_counter = 0, population = 0, generation = 0, fps_count = 0, cel=0, total_cels = 0;

int delay_msec = 10; //depinde de fps
int grid = 1;
int mouse = 1;
int paused = 1;
int size = 25;

char filename[8];

int pan_vert = 0;
int pan_horiz = 0;

unsigned char *table;
unsigned char *nextgen;


Button buttons[9] = {
					  {242,19,'+',0,TEXT_COLOR2,0},
					  {253,19,'-',0,TEXT_COLOR2,0},
					  {242,39,'*',0,TEXT_COLOR2,0},
					  {253,39,'o',0,TEXT_COLOR2,0},
					  {242,49,'h',0,TEXT_COLOR2,0},
					  {253,49,'g',0,TEXT_COLOR2,0},
					  {242,9,'Q',0,TEXT_COLOR2,0},
					  {242,29,'L',0,TEXT_COLOR2,0},
					  {253,29,'S',0,TEXT_COLOR2,0}
					  };
					  


void initialize(void)
{
	if(mouse){
		if(!InstallMouse()){
            //printf("\n\n\t Mouse driver not loaded.\n");
            //exit(1);
			mouse = 0;
		}

		SetMousePosi(1,1);
	}
	
	initialize_graphics(true);
   	ctrlbrk(ctrlbrk_handler);
   	hook_keyb_int();
	
	init_chars_15();
}


//unsigned short int get_msec(){
word get_msec(){
	 struct dostime_t t;
	_dos_gettime(&t);
	//return t.hour * 3600 * 1000 + t.minute * 60 * 1000  + t.second * 1000  + t.hsecond;
	return  t.minute * 60 * 1000  + t.second * 1000  + t.hsecond;
	//return  t.second * 1000  + t.hsecond;
 }

void quit(){
	exit_graphic();
	delay(200);
	free(table);
	free(nextgen);
	delay(200);
	unhook_keyb_int();
	delay(400);
	exit(1);
}


void pause(){
	paused = 1;
	buttons[5].c = 'g';
}

void play(){
	paused = 0;
	buttons[5].c = 'p';
}

void draw_ui(){

	char fps_c[20];
	int size_of_v_bar , size_of_h_bar ;
	int x,y,i;
	
	rect_fill(199*a_ratio+1,1, 318, 198, 17);
	
	rect_fast(0,0, 199*a_ratio, 199, BORDER_COLOR);
	rect_fast(199*a_ratio,0,319,199, BORDER_COLOR);
	
	itoa(fps_count,fps_c,10);
	put_str_15(264,10,"FPS:",TEXT_COLOR,0);
	put_str_15(284,10,fps_c,TEXT_COLOR2,0);
	
	itoa(delay_msec,fps_c,10);
	put_str_15(264, 20,"DELAY:",TEXT_COLOR,0);
	put_str_15(289, 20,fps_c,TEXT_COLOR2,0);
	
	
	put_str_15(264, 30,"FILE:",TEXT_COLOR,0);
	filename[8] = 0;
	put_str_15(284, 30,filename,TEXT_COLOR2,0);
	
	itoa(population,fps_c,10);
	put_str_15(264, 40,"POP:",TEXT_COLOR,0);
	put_str_15(284, 40,fps_c,TEXT_COLOR2,0);
	
	
	itoa(generation,fps_c,10);
	put_str_15(264, 50,"GEN:",TEXT_COLOR,0);
	put_str_15(284, 50,fps_c,TEXT_COLOR2,0);
	
	/*
	itoa(pan_horiz,fps_c,10);
	//rect_fill(280,50, 320, 58, 0);	
	put_str_15(265, 50,"HOR:",TEXT_COLOR,0);
	put_str_15(285, 50,fps_c,TEXT_COLOR,0);
	
	itoa(pan_vert,fps_c,10);
	//rect_fill(280,58, 320, 66, 0);	
	put_str_15(265, 58,"VER:",TEXT_COLOR,0);
	put_str_15(285, 58,fps_c,TEXT_COLOR,0);
	
	itoa(GetPosX(),fps_c,10);
	//rect_fill(280,66, 320, 72, 0);	
	put_str_15(265, 66,"MX:",TEXT_COLOR,0);
	put_str_15(285, 66,fps_c,TEXT_COLOR,0);
	
	itoa(GetPosY(),fps_c,10);
	//rect_fill(280,72, 320, 80, 0);	
	put_str_15(265, 72,"MY:",TEXT_COLOR,0);
	put_str_15(285, 72,fps_c,TEXT_COLOR,0);
	*/

	if(mouse){
		x = GetPosX();
		y = GetPosY();
					
		if( x <= 198*a_ratio && y <= 198){
			cel = x/a_ratio/zoom + pan_horiz + y/zoom*size+pan_vert*size + 1;
		}else{
			cel = 0;
		}
		
		sprintf(fps_c,"%u",( cel > size * size ? 0 : cel ) );
		put_str_15(260, 80,"CELL:",TEXT_COLOR,0);
		put_str_15(285, 80,fps_c,TEXT_COLOR2,0);
	}
	
	
	itoa(size,fps_c,10);
	put_str_15(260, 90,"SIZE:",TEXT_COLOR,0);
	put_str_15(285, 90,fps_c,TEXT_COLOR2,0);
	
	for(i = 0; i<= 8; i++)
		button(buttons[i]);
	
	
	put_str_15(270, 190,(paused ? "PAUSED":""),TEXT_COLOR2,0);

	size_of_h_bar =  198*a_ratio - ( size - 198*a_ratio/zoom + 9 )  ;
	if(size_of_h_bar <= 197*a_ratio){
		
	/*
		itoa(size_of_h_bar,fps_c,10);
		//rect_fill(280,72, 320, 80, 0);	
		put_str_15(260, 88,"HBAR:",TEXT_COLOR,0);
		put_str_15(280, 88,fps_c,TEXT_COLOR,0);
	*/
		size_of_h_bar = size_of_h_bar >= 198*a_ratio ? 198*a_ratio : size_of_h_bar;
		rect_fill(1 + pan_horiz,197, pan_horiz + size_of_h_bar , 198, TEXT_COLOR2);	
	}

	
	size_of_v_bar =  ( 198*a_ratio - ( size - 198*a_ratio/zoom  + 7)  ) /a_ratio ;
	if(size_of_v_bar <= 198 ){
		
	/*
		itoa(size_of_v_bar,fps_c,10);
		//rect_fill(280,72, 320, 80, 0);	
		put_str_15(260, 96,"VBAR:",TEXT_COLOR,0);
		put_str_15(280, 96,fps_c,TEXT_COLOR,0);
	*/
		size_of_v_bar = size_of_v_bar >= 198 ? 198 : size_of_v_bar;
		rect_fill(197*a_ratio, 1 + pan_vert/a_ratio ,198*a_ratio, pan_vert/a_ratio + size_of_v_bar , TEXT_COLOR2);	
	}
	
	if(mouse){
		RestrictMousePtr(0,0,318,197);
		GetMouseStatus();
		put_str_15(GetPosX(),GetPosY(),"m",WHITE,240);
	}

}


void draw( char  *tbl){
	
	word p, k;
	int x,y,color;
	
	rect_fill(0,0, 199*a_ratio, 199, 0);
	
	x=1;
	y=1;
	k = 0;
	p = pan_vert*size + pan_horiz;

	while(p < total_cels){

		if( x+zoom <= 198*a_ratio &&  y+zoom <= 198){// && nextgen[p]){
			
			color =  tbl[p] == 1 ? TEXT_COLOR : 19;
		
			if(zoom > 1){

				if(grid){
					rect_fast(x,y, x+zoom*a_ratio, y+zoom, 0 );	
					rect_fill(x+1,y+1, x+zoom*a_ratio-1, y+zoom-1, color);	
					
				}else{
					rect_fill(x,y, x+zoom*a_ratio, y+zoom, color);	
				}
				
			}else{
				plot_pixel(x,y,color);
			}
		}
				
		if(p%size == size-1 ){
			y += zoom;
			x = 1;
			k++;
			p = size*k  + pan_vert*size  + pan_horiz;
		}else{
			x += zoom*a_ratio;
			p++;
		}
	}
	draw_ui();
}

void write_gol_file(){

	word i = 0;
	FILE *fp;
	char path[30];
	mkdir("SAVES");
	sprintf(path,"SAVES\\%s.gol",filename);
	
	fp = fopen(path,"w+");

	fprintf(fp,"%d\n",size);
	
	for(;i < total_cels; i++){
		if(table[i])
			fprintf(fp,"%hu\n",i);
	}
	
	fclose(fp);
}

void save_file(){

	char ch;
	char savename[8];
	int j=0;

	if(!paused)
		pause();
	
	strcpy(savename,filename);
	j = strlen(savename);
	j = strcmp(savename,"        ") == 0 ? 0 : j ;
	
	
	while( 1 ){
		
		if(get_key_status(SCAN_ENTER)){
			break;
		}
		
		if(get_key_status(SCAN_ESC)){
			return;
		}
		
		if(get_key_status(SCAN_DELETE)){
			j =  0;
			strcpy(savename,"        ");
			delay(KEY_DELAY);
		}
		
		if(get_key_status(SCAN_BACKSPACE)){
			j = j > 0  ? j - 1 : j;
			savename[j] = '\0';
			delay(KEY_DELAY);
		}
		
		ch =  toupper(get_pressed_key());
		if(ch != '#' && j < 8){
			savename[j]=ch;
			//j = j < 8 ? j + 1 : j;
			j++;
			delay(KEY_DELAY);
		}
		
		draw(table);
		
		rect_fast(100,90, 170, 136, BORDER_COLOR);
		rect_fill(101,91, 169, 135, 0);
		
		put_str_15(118,100,"SAVE:",TEXT_COLOR,0);
		rect_fill(117,110, 150, 116, RED);
		savename[8] = 0;
		put_str_15(118,110,savename,WHITE,0);
		
		RestrictMousePtr(0,0,318,197);
		GetMouseStatus();
		put_str_15(GetPosX(),GetPosY(),"m",WHITE,240);
		show_buffer();
	}
	
	if(strlen(savename) > 0){
		strcpy(filename,savename);
		write_gol_file();
	}
}


void clear_table(){
	memset(table,0,total_cels);
	memset(nextgen,0,total_cels);
	population = 0;
	generation = 0;
	pause();
}


void read_gol_file(){
	
	word i = 0, j = 0;
	FILE *fp;
	char path[30];
	int new_size;
	
	
	delay(400);
	
	sprintf(path,"SAVES\\%s.gol",filename);
	
	fp = fopen(path,"r+");
	
	fscanf(fp,"%d[^\n]",&new_size);
	fgetc(fp);
	new_size = new_size > MAX_SIZE ? MAX_SIZE : new_size;
	pan_vert = pan_horiz = 0;
	
	if(new_size != size){
		size = new_size;
		total_cels = size*size;
		table = (char *)realloc(table,total_cels);
		nextgen = (char *)realloc(nextgen,total_cels);
		
	}else{
		size = new_size;
	}
	
	population = generation = pan_horiz = pan_vert = 0;
	
	clear_table();
	
	while((fscanf(fp,"%hu[^\n]",&i))!=EOF){
		fgetc(fp);
		if(i > total_cels)
			break;
		table[i]=1;
		nextgen[i]=1;
		j++;
	}
	
	population = j;
	fclose(fp);
}

void load_file(){

	int i = 0,j;
	int files_no;
	
	char *files[8];
	char *tmp;// = *files;
	//char files[255][8];
	struct dirent *entry;
	DIR *dir;

	dir = opendir(".\\SAVES");
	
	if(!paused)
		pause();

	while( (entry = readdir(dir)) != NULL){

			if(strcmp (entry->d_name,"..") == 0 || strcmp (entry->d_name,".") == 0 
					|| !( 	entry->d_name[strlen(entry->d_name)-4] == '.' && 
							toupper(entry->d_name[strlen(entry->d_name)-3]) == 'G' && 
							toupper(entry->d_name[strlen(entry->d_name)-2]) == 'O' && 
							toupper(entry->d_name[strlen(entry->d_name)-1]) == 'L')) continue;
		
			files[i] = (char *) malloc(8);
			//entry->d_name[strlen(entry->d_name)-4] = '\0';
			
			//files[i] = (char *) malloc(sizeof(strlen(entry->d_name)-4));
			
			strncpy(files[i],entry->d_name,8);
			
			for(j=0;j<=8;j++){
				if(files[i][j] == '.'){
					files[i][j] = 0;//'\0';
					break;
				}
			}
			
			//files[i][8] = 0;
			//files[i][strlen(files[i])-4]='\0'; //retin numele fara extensie
			i++;
	}
	
	files_no = i > 0 ?  i - 1 : 0;
	
	if(files_no == 0)
		return;
		
	i = 0;
	while( 1 ){
	
		if(get_key_status(SCAN_ENTER)){
			strcpy(filename,files[i]);
			filename[8] = 0;
			break;
		}
		
		if(get_key_status(SCAN_ESC)){
			for(i = 0;i <= files_no; i++){
				free(files[i]);
			}
			closedir(dir);
			return;
		}
		
		if(get_key_status(SCAN_UP_ARROW)){
				i = i > 0 ? i-1 : 0;
				delay(KEY_DELAY);
		}
		
		if(get_key_status(SCAN_DOWN_ARROW)){
				i = i < files_no ? i+1 : files_no;
				delay(KEY_DELAY);
		}
		
		
		draw(table);
		rect_fast(100,90, 170, 136, BORDER_COLOR);
		rect_fill(101,91, 169, 135, 0);
		
		put_str_15(116,95,"LOAD:",TEXT_COLOR,0);
		rect_fill(116,104, 150, 132, RED);
		rect_fast(115,103, 151, 111, WHITE);
		put_str_15(118,104,files[i],WHITE,0);
		if(i + 1 <= files_no) put_str_15(118,114,files[i+1],WHITE,0);
		if(i + 2 <= files_no) put_str_15(118,124,files[i+2],WHITE,0);
		
		RestrictMousePtr(0,0,318,197);
		GetMouseStatus();
		put_str_15(GetPosX(),GetPosY(),"m",WHITE,240);

		show_buffer();
	}
	
        /*
	tmp = files;
	while(tmp != NULL){
		free(tmp);
		tmp++;
	}
	//free(files);
         */
        
        for(i=0;i<=files_no;i++)
            free(files[i]);

	closedir(dir);
	
  read_gol_file();
  if(!paused)
	pause();

}

void help(){
	if(!paused)
	pause();

	while(1){
		if(get_key_status(SCAN_ESC) ){
			return;
		}
		
		draw(table);
		rect_fill(7,7, 190*a_ratio, 136, 0);
		rect_fast(7,7, 190*a_ratio, 136, BORDER_COLOR);
		
		
		put_str_15(10,10,"HELP:",TEXT_COLOR,0);
		put_str_15(10,20," - USE ARROW KEYS FOR SCROLL TABLE",TEXT_COLOR,0);
		put_str_15(10,30," - HOME AND END FOR FIRST OR LAST CELL",TEXT_COLOR,0);
		put_str_15(10,40," - INSERT AND DEL FOR RANDOM OR EMPTY TABLE",TEXT_COLOR,0);
		put_str_15(10,50," - PLUS AND MINUS FOR INCREASE OR DECREASE TABLE SIZE",TEXT_COLOR,0);
		put_str_15(10,60," - A AND D FOR INCREASE OR DECREASE DELAY",TEXT_COLOR,0);
		put_str_15(10,70," - SPACE FOR PAUSE OR UNPAUSE THE GAME",TEXT_COLOR,0);
		put_str_15(10,80," - N FOR NEXT GENERATION",TEXT_COLOR,0);
		put_str_15(10,90," - S AND L FOR SAVE OR LOAD GAME FILE",TEXT_COLOR,0);
		put_str_15(10,100," - LEFT OR RIGHT MOUSE FOR SET OR UNSET CELL",TEXT_COLOR,0);
		put_str_15(10,110," - Q FOR QUIT",TEXT_COLOR,0);
		
		
		RestrictMousePtr(0,0,318,197);
		GetMouseStatus();
		put_str_15(GetPosX(),GetPosY(),"m",WHITE,240);

		show_buffer();
		
	}
}

void random_table(){
	word i;
	for(i = 0; i < size * size; i++){
		table[i] = random(2);
		nextgen[i] = random(2);
		generation = 0;
	}
}




void check_buttons(int x, int y){
	int i;
	for(i = 0; i<= 8; i++){
		if( x >= buttons[i].x && x <= buttons[i].x+8  && y >= buttons[i].y && y<= buttons[i].y+8 ){
			
			switch(buttons[i].c){
				case '+':
					delay_msec = delay_msec < MAX_DELAY ? delay_msec + 10 : delay_msec;
				break;
				case '-':
					delay_msec = delay_msec > 0 ? delay_msec - 10 : delay_msec;
				break;
				case '*':
					random_table();
				break;
				case 'o':
					clear_table();
				break;
				case 'g':
					play();
				break;
				case 'p':
					pause();
				break;
				case 'h':
						memcpy(table,nextgen,size * size);	
						generation++;
				break;
				case 'L':
				delay(KEY_DELAY);
					load_file();
					delay(KEY_DELAY);
				break;
				case 'S':
					save_file();
				break;
				case 'Q':
					quit();
				break;
			}
			delay(KEY_DELAY);
		}
	}
}


void on_usr_input(){
		word i;
		int x,y;
		
			if(get_key_status(SCAN_A)){
				delay_msec = delay_msec < MAX_DELAY ? delay_msec + 10 : delay_msec;
				delay(KEY_DELAY);
				return;
			}
				
			if(get_key_status(SCAN_D)){
				delay_msec = delay_msec > 0 ? delay_msec - 10 : delay_msec;
				delay(KEY_DELAY);
				return;
			}
		
				
				if(get_key_status(SCAN_N)){
					memcpy(table,nextgen,size * size);	
					generation++;
					delay(KEY_DELAY);
					return;
				}
				
				
				if(get_key_status(SCAN_HOME)){
					pan_horiz = 0;
					pan_vert = 0;
					return;
				}
				
				
				if(get_key_status(SCAN_END)){
					pan_horiz = size - 198*a_ratio/zoom + 9;
					pan_vert =  size - 198/zoom;
					return;
				}
				
				if(get_key_status(SCAN_KP_PLUS) || get_key_status(SCAN_EQUALS)){
					
					if(size < MAX_SIZE){
						size++;
						total_cels = size*size;
						table = (char *)realloc(table,total_cels);
						nextgen = (char *)realloc(nextgen,total_cels);
						population = generation = pan_horiz = pan_vert = 0;
						clear_table();
						return;
					}
					return;
				}
				
				if(get_key_status(SCAN_KP_MINUS) || get_key_status(SCAN_MINUS)){
					if(size > 0){
						size--;
						total_cels = size*size;
						table = (char *)realloc(table,total_cels);
						nextgen = (char *)realloc(nextgen,total_cels);
						population = generation = pan_horiz = pan_vert = 0;
						clear_table();
						return;
					}
					return;
				}
				
				if(get_key_status(SCAN_RIGHT_ARROW)){
					if(pan_horiz >= size - 198*a_ratio/zoom + 8 )	
						pan_horiz = pan_horiz;
					else
						pan_horiz += 1;
					return;
				}
				
				if(get_key_status(SCAN_DOWN_ARROW)){
					 if(pan_vert >= size - 198/zoom  )
						 pan_vert = pan_vert;
					 else
						pan_vert += 1;
					return;
				}
					
				if(get_key_status(SCAN_LEFT_ARROW)){
					if( pan_horiz  <= 0 )
						pan_horiz = 0;
					else	
						pan_horiz -= 1;
					return;
				}
				
				 if(get_key_status(SCAN_UP_ARROW)){
					 
					 if(pan_vert  <= 0)
						 pan_vert = 0;
					 else
						pan_vert -= 1;
					return;
				 }
				
				if(get_key_status(SCAN_SPACE)){
					//delay(KEY_DELAY);
					if(paused)
						play();
					else 
						pause();
					delay(KEY_DELAY);
					return;
				}
				
				if(get_key_status(SCAN_DELETE)){
					clear_table();
					delay(KEY_DELAY);
					return;
				}
				
				if(get_key_status(SCAN_INSERT)){
					random_table();
					delay(KEY_DELAY);
					return;
				}

				if(get_key_status(SCAN_Q)) {
					quit();
				}
				
				if(get_key_status(SCAN_S)) {
						delay(KEY_DELAY);
						save_file();
						delay(KEY_DELAY);
						return;
				}
				
				if(get_key_status(SCAN_L)) {
						delay(KEY_DELAY);
						load_file();
						delay(KEY_DELAY);
						return;
				}
				
				
				if(get_key_status(SCAN_F1 )) {
						help();
						return;
				}
				
				
				if(mouse){
					
					GetMouseStatus();
					x = GetPosX();
					y = GetPosY();
					
					if(GetButton() == 1){
						if( x <= 198*a_ratio && y <= 198){
							cel = (word) x/a_ratio/zoom + pan_horiz + (word) y/zoom*size + (word)  pan_vert*size;
							table[cel] =  1;
							nextgen[cel] =  1;
						}else{
							check_buttons(x, y);
						}
					}
					
					if(GetButton() == 2 && x <= 198*a_ratio && y <= 198){
						cel = (word) x/a_ratio/zoom + pan_horiz + (word) y/zoom*size + (word)  pan_vert*size;
						table[cel] =  0;
						nextgen[cel] =  0;
					}
				}
}


void main(){

		word i, popcount=0;
		int tstart_upd,tend_upd,k;
		word max_gen = 1000000;

		int n_top = 0;
		int n_bottom = 0;
		int n_left = 0;
		int n_right = 0;
		int n_topleft = 0;
		int n_topright = 0;
		int	n_bottomleft = 0;
		int n_bottomright = 0;
		int live_neighbours = 0;
		
		int test_start;
		char file_to_load[15];
		
ini_t *config = ini_load("golvga.ini");
ini_sget(config, "gameoflife", "delay", "%d", &delay_msec);
delay_msec = delay_msec > MAX_DELAY ? MAX_DELAY : delay_msec;
ini_sget(config, "gameoflife", "table_size", "%d", &size);
size = size > MAX_SIZE ? MAX_SIZE : size;
ini_sget(config, "gameoflife", "max_gen", "%llu", &max_gen);
ini_sget(config, "gameoflife", "start", "%d", &test_start);
ini_sget(config, "gameoflife", "file", "%s", file_to_load);
//ini_sget(config, "gameoflife", "file", "%s", filename);
ini_free(config);

		

		total_cels = size*size;
		
		table = (unsigned char *) malloc(total_cels*sizeof(unsigned char));
		nextgen = (unsigned char *) malloc(total_cels*sizeof(unsigned char));
		
		
		
        initialize();
		randomize(); 
		clear_table();
		
		if(test_start == 1){
			random_table();
		}else if(test_start == 2){
			
			// load from file
			for(k = 0;k<8;k++){
				if(file_to_load[k] == '.') {
					filename[k] =  '\0';
					break;
				}
				filename[k] = toupper(file_to_load[k]);
			}
			
			if(strlen(filename) > 2)
				read_gol_file();
			
		}else{
			strcpy(filename,"        ");
		}

		draw(table);
		show_buffer();
		
		tstart_upd = tstart = get_msec();
		
		fps_counter = 0;
        while(1){
			
			popcount=0;
		  
			for(i = 0;i<total_cels;i++){
				
				n_top = table[( i - size )];
				n_bottom = table[( i + size )];
				
				n_left = table[(i - 1)];
				n_right = table[(i + 1)];
				
				n_topleft = table[( i - size - 1)];
				n_topright = table[( i - size + 1)];
				
				n_bottomleft = table[( i + size - 1)];
				n_bottomright = table[( i + size + 1)];
				
				
				if(i%size == 0){ //left
					n_left = 0;
					n_topleft = 0;
					n_bottomleft = 0;
				}
				
				if(i%size == size-1){//right
					n_right = 0;
					n_topright = 0;
					n_bottomright = 0;
				}
				
				if(i<=size-1){//top
					n_top = 0;
					n_topright = 0;
					n_topleft = 0;
				}
				
				if(i >= total_cels - size && i< total_cels){//bottom
					n_bottom = 0;
					n_bottomleft = 0;
					n_bottomright = 0;
				}
				
				live_neighbours =  n_top + n_bottom + n_left + n_right + n_topleft + n_topright + n_bottomleft + n_bottomright;
			
				
					nextgen[i] = table[i] == 1 && live_neighbours == 2 || live_neighbours == 3  ? 1 : 0;
					popcount += table[i];
			}	

			population = popcount;
			fps_counter++;
			
			on_usr_input() ;
			
			tend_upd = tend = get_msec();
			
			if( (tend - tstart) >= 1000 ){
				fps_count = fps_counter;
				fps_counter = 0;
				tstart = get_msec();
			}
			
			if( (tend_upd - tstart_upd) >= delay_msec){
				
				if(!paused){
					memcpy(table,nextgen,total_cels);	
					generation++;
				}
				
				tstart_upd = get_msec();
				
			}else{
				//draw(table, table, size);
			}
				
			if(!paused)
				draw(nextgen);
			else
				draw(table);

			show_buffer();
    }
}
