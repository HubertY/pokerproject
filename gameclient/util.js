exports.sum = function(arr){
    let ret = 0;
    for(let x of arr){
        ret += x;
    }
    return ret;
}

exports.scale = function(arr, n){
    return arr.map((x)=> x*n);
}

exports.multiply = function(arr1, arr2){
    return arr1.map((x,i)=> ((x * arr2[i]) || 0));
}

exports.normalize = function(arr, tot = exports.sum(arr)){
    return exports.scale(arr, 1/tot);
}

exports.mask = function(arr){
    return arr.map(x => x > 0 ? 1 : 0);
}

