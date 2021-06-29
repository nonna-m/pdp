// 74. Search a 2D Matrix - https://leetcode.com/problems/search-a-2d-matrix/
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var binarySearch = function (sortedArray, target) {
  if (sortedArray.length <= 2)
    return sortedArray[0] === target || sortedArray[1] === target;
  let s = 0;
  let e = sortedArray.length;
  const len = e;
  let m = Math.floor(len / 2);
  while (m > s && m < e) {
    if (target === sortedArray[m]) return true;
    if (target > sortedArray[m]) s = m;
    else e = m;
    m = s + Math.floor((e - s) / 2);
  }
  return target === sortedArray[m];
};

var searchMatrix = function (matrix, target) {
  const m = matrix.length;
  const sc = matrix[0].length - 1;
  let s = 0; // start
  let e = m - 1; // end
  let mid = Math.floor(e / 2); // middle
  if (m == 1) return binarySearch(matrix[0], target);
  if (m == 2) {
    const item = matrix[0][sc];
    if (target === item) return true;
    if (target > item) return binarySearch(matrix[1], target);
    return binarySearch(matrix[0], target);
  }
  while (mid > s && mid < e) {
    const item = matrix[mid][sc];
    if (target === item) return true;
    if (target > item) {
      if (e - mid == 1) return binarySearch(matrix[e], target);
      s = mid;
      mid = Math.floor((e - s) / 2) + s;
    } else {
      if (mid - s == 1) {
        if (target > matrix[s][sc]) return binarySearch(matrix[mid], target);
        return binarySearch(matrix[s], target);
      }
      e = mid;
      mid = Math.floor((e - s) / 2) + s;
    }
  }
  return false;
};

// 207. Course Schedule - https://leetcode.com/problems/course-schedule/
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function (numCourses, prerequisites) {
  // if (!prerequisites.length) return true;
  // for (let i = 0; i < prerequisites.length; i++) {
  //     if (prerequisites[i][0]===prerequisites[i][1]) return false;
  // }
  // const count = prerequisites.flat().reduce((acc, el) => acc.includes(el) ? acc : [...acc, el], []).length
  // return prerequisites.length < count;
  for (let i = 0; i < prerequisites.length; i++) {
    let cycle = prerequisites[i][1];
    const checkedIndexes = [];
    // console.log(i, ' --- ');
    for (let j = 0; j < prerequisites.length; j++) {
      if (cycle == prerequisites[j][0] && !checkedIndexes.includes(j)) {
        if (prerequisites[i][0] == prerequisites[j][1]) {
          return false;
        }
        cycle = prerequisites[j][1];
        checkedIndexes.push(j);
        // console.log(j)
        j = -1;
      }
    }
  }
  return true;
};
