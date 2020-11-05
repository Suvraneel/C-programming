

void sort_by_area(triangle* tr, int n) {
    int i, j;
    double tempa, tempb, tempc;
    double area[n], p[n];

    for (i=0; i<n; i++) {
        p[i] = (tr[i].a + tr[i].b + tr[i].c)/2.0 ;
        area[i] = p[i] * (p[i] - tr[i].a) * (p[i] - tr[i].b) * (p[i] - tr[i].c);
    }

    //bubble sort 
    for (i=0; i<n; i++) {
        for (j=0; j< n-i-1; j++) {
            if (area[j]>area[j+1]) {
            
                double temp=area[j];
                area[j]=area[j+1];
                area[j+1]=temp;

                tempa  =   tr[j+1].a;
                tempb  =   tr[j+1].b;
                tempc  =   tr[j+1].c;

                tr[j+1].a   =   tr[j].a;
                tr[j+1].b   =   tr[j].b;
                tr[j+1].c   =   tr[j].c;
            
                tr[j].a =   tempa;
                tr[j].b =   tempb;
                tr[j].c =   tempc;
                }
            }
        }
   
}

