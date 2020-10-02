// Comb sort is a relatively simple sorting algorithm originally designed by Włodzimierz Dobosiewicz and Artur Borowy in 1980.
// Comb sort improves on bubble sort.
// https://en.wikipedia.org/wiki/Comb_sort

/**
 * Sorts an array of numbers using comb sort.
 * @param {Array} data 
 */
function combSort(data){
    const length = data.length;

    const shrink = 1.3; // Set the gap shrink factor
    let _gap = length; // Initialize gap size
    const out = [...data]; // Copy data to the output variable
    let sorted = false;

    while(!sorted){
        // Update the gap value for a next comb
        _gap /= shrink;
        let gap = Math.round(_gap);
        if(gap <= 1){
            sorted = true; // If there are no swaps this pass, we are done
            gap = 1;
        }

        // A single "comb" over the input list
        for(let i = 0; i < length - gap; i++){
            const sm = gap + i;

            if(out[i] > out[sm]){
                // Swap out[i] and out[sm]
                // out[i]   out[sm]
                //   |         |
                //   a         b

                const a = out[i];
                const b = out[sm];

                //  a         b
                //  |         |
                // out[sm]  out[i]

                out[sm] = a;
                out[i] = b;
                sorted = false;

                // If this assignment never happens within the loop,
                // then there have been no swaps and the list is sorted.
            }
        }
    }

    return out;
}

// Test code.
console.log(combSort([3, 5, 8, 1, 2, 123, 43, 86]));
console.log(combSort([1, 2, 3]));
console.log(combSort([3, 6, 3, 2, 7]));