//LR5 custom header to make actual programm code a bit smaller

struct skills {
	char OS[12];
	char CodeLang[8];
	char DB[8];
};

struct SE_ {//SE - SoftwareEngineer
	char Name[24];
	char Company[24];
	int WE;//WE  -WorkExpirience
	skills software;
};

class SE_list_manip {
public:
	static void print_heading();

	static void print_ending();

	static void print_SE(struct SE_ SE[], int i);

	static void SE_list_sort(struct SE_ SE[], int SE_amount);//bubble sort
};
