// Wierd Faculty

public static int exam(List<Integer> v) {
    int totalSum = 0;
    for(int score: v) {
        if (score == 0) totalSum -= 1;
        else totalSum += 1;
    }

    int currSum = 0;
    for(int i =0; i < v.size(); i++) {
        if (currSum > totalSum) return i;
        currSum += v.get(i) == 0 ? -1 : 1;
        totalSum -= v.get(i) == 0 ? -1 : 1;
    }
    return v.size();
}


def weirdFaculty(v):
  n = len(v)
  # Convert all the zeros to -1 as
  # the zero gives us the negative score of -1

  for i in range(n):
    if not v[i]:
      v[i] = -1
  
   # Find the total sum

  totalSum = sum(v)
  currSum = 0

  # Find the point where current sum is
  # greater than the total sum

  for i in range(n):
    if currSum > totalSum:
      return i
    currSum += v[i]
    totalSum -= v[i]
  return n