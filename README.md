# Implementation of Random Walks on Polytopes
C++ implementation with python wrapper of Vaidya walk and John walk introduced by the paper "Fast MCMC Algorithms on Polytopes"
https://arxiv.org/abs/1710.08165
by Yuansi Chen, Raaz Dwivedi, Martin J. Wainwright, Bin Yu

## Use Guide
- To install the package to default python
```bash
pip install .
```
- Import the library
```python
import polytopewalk
```
- Example
```python
import polytopewalk as pw
# dimension
d = 2
(A, b) = pw.define_polytope(d, rep=0)
# radius 
r = 0.5
nb_samples = 10
nb_iters = 20

# generate samples with vaidya and john walk
samples_vaidya = pw.run_vaidya_walk(nb_samples, nb_iters, A, b, r)
samples_john = pw.run_john_walk(nb_samples, nb_iters, A, b, r)
```


## License and Citation
Code is released under MIT License.
Please cite the paper if the code helps your research:

```bib
@article{chen2017fast,
    title={Fast MCMC sampling algorithms on polytopes},
    author={Chen, Yuansi and Dwivedi, Raaz and Wainwright, Martin J and Yu, Bin},
    journal={arXiv preprint arXiv:1710.08165},
    year={2017}
}
```
