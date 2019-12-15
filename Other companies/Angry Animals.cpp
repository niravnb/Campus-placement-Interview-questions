public static void AngryAnimals(int N, int [] a, int [] b){
 
	/* The following array will contain the least animal 
	that animal i has conflict with */
 
	int [] conflicts = new int[N];
	int i = 0;
	Arrays.fill(conflicts, N);
	for(i = 0; i < a.length; i++){
		int l = Math.min(a[i], b[i]);
		int h = Math.max(a[i], b[i]);
		conflicts[l] = Math.min(conflicts[l], h);
	}
 
	/* The following array will contain at the index i the maximum length of 
	interval including the animal i,
	Also note that the maximum interval including the animal i depends on the 
	least animal i has conflict with and also the maximum interval including 
	the animal i+1 */
 
	int [] aux_con = new int[N];
	
	//Since N-1 animal wont have any conflicts with animal bigger than itself
	aux_con[N-1] = N;
	
	int ways = 0;
 
	for(i = N-2; i > -1; i-=1){
		aux_con[i] = Math.min(conflicts[i], aux_con[i+1]);
 
		/* suppose i = 0, aux_con[i] = 3;
			intervals are as follows :
			[0, 1, 2]
			[0, 1]
			[0]
			the number of possible intervals increases by aux_con[i] - i
			which is the length of the interval
		*/
 
		ways += aux_con[i] - i;
	}
 
	System.out.println("Total non-conflicting intervals are : "+ways);