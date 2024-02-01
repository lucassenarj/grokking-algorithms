/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function(names, heights) {
    let index = 0;
    const sorted_array = [];
    const sorted_names = [];
    const size = heights.length;

    for (let i = 0; i < size; i++) {
        let item = heights[i];
        index = i;
        
        for (let j = 0; j < size; j++) {
            if (heights[j] > item) {
                item = heights[j];
                index = j;
            }
        }
        heights[index] = Number.MIN_SAFE_INTEGER;
        sorted_array.push(index);
    }

    for (let i = 0; i < size; i++) {
        sorted_names.push(names[sorted_array[i]]);
    }
    return sorted_names;
};

const names1 = ["Mary", "John", "Emma"];
const heights1 = [180, 165, 170];
console.log(sortPeople(names1, heights1)); //expected result: ["Mary","Emma","John"];

const names2 = ["Alice","Bob","Bob"];
const heights2 = [155,185,150];
console.log(sortPeople(names2, heights2)); //expected result: ["Bob","Alice","Bob"];

const names3 = ["IEO","Sgizfdfrims","QTASHKQ","Vk","RPJOFYZUBFSIYp","EPCFFt","VOYGWWNCf","WSpmqvb"];
const heights3 = [17233,32521,14087,42738,46669,65662,43204,8224];
console.log(sortPeople(names3, heights3)); //expected result: ["EPCFFt","RPJOFYZUBFSIYp","VOYGWWNCf","Vk","Sgizfdfrims","IEO","QTASHKQ","WSpmqvb"]

