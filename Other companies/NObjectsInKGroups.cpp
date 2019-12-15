function f(n, k, memo={}){
  if (k == 0 && n == 0)
    return 1

  if (n <= 0 || k <= 0)
    return 0

  let key = String([n, k]) // Thanks to comment by user633183

  if (memo.hasOwnProperty(key))
    return memo[key]

  return memo[key] = f(n - k, k, memo) + f(n - 1, k - 1, memo)
}
