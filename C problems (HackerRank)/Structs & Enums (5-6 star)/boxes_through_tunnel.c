
struct box
{
	int length[100];
    int width[100];
    int height[100];
};

typedef struct box box;

int get_volume(box b) {
	int volume = (*b.length) * (*b.width) * (*b.height) ;
    return volume;
}

int is_lower_than_max_height(box b) {
	if (*b.height < MAX_HEIGHT) {
    return 1;
    }
    else {
    return 0;
    }
}

