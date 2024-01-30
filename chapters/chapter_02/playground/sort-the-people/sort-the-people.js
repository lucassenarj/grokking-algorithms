/**
 * 
 * @param {numers[]} heights 
 * @returns {number}
 */
function get_highest_indice(heights) {
    const size = heights.length;
    let highest = heights[0];
    let highestIndex = 0;

    for (let i = 0; i < size; i++) {
        if (heights[i] > heights[highestIndex]) {
            highest = heights[i];
            highestIndex = i;
        }
    }
    return highestIndex;
}

/**
 * @param {string[]} names
 * @param {number[]} heights
 * @return {string[]}
 */
var sortPeople = function(names, heights) {
    const sortedHeight = [];
    const sortedNames = [];
    const length = heights.length;
    let indiceDoMaiorValor;

    for (let i = 0; i < length; i++) {
        indiceDoMaiorValor = get_highest_indice(heights);
        sortedHeight.push(indiceDoMaiorValor);
        heights[indiceDoMaiorValor] = 0;
    }
    for (let i = 0; i < length; i++) {
        sortedNames.push(names[sortedHeight[i]]);
    }
    return sortedNames;
};

const names1 = ["Mary", "John", "Emma"];
const heights1 = [180, 165, 170];
console.log(sortPeople(names1, heights1)); //expected result: ["Mary","Emma","John"];

const names2 = ["Alice","Bob","Bob"];
const heights2 = [155,185,150];
console.log(sortPeople(names2, heights2)); //expected result: ["Bob","Alice","Bob"];

