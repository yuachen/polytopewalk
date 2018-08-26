from unittest import TestCase
import numpy as np
import polytopewalk as pw

class TestPolytopeWalk(TestCase):
    
    def test_define_polytope_b(self):
        (A, b) = pw.define_polytope(10)
        self.assertEqual(b.shape[0], 20)

    def test_define_polytope_A(self):
        (A, b) = pw.define_polytope(10, rep=3)
        self.assertEqual(A.shape[0], 160)

    def test_dikin_walk(self):
        d = 2
        (A, b) = pw.define_polytope(d, rep=0)
        r = 0.5
        nb_samples = 10
        nb_iters = 20
        initialization = np.zeros(d)

        samples = pw.run_dikin_walk(nb_samples, nb_iters, A, b, r)
        self.assertEqual(samples.shape[1], nb_samples)
        # the first coordinate of the last sample is expected to diverge from zero.
        self.assertFalse(np.isclose(samples[0, 0, -1], 0.))

    def test_vaidya_walk(self):
        d = 2
        (A, b) = pw.define_polytope(d, rep=0)
        r = 0.5
        nb_samples = 10
        nb_iters = 20
        initialization = np.zeros(d)

        samples = pw.run_vaidya_walk(nb_samples, nb_iters, A, b, r)
        self.assertEqual(samples.shape[1], nb_samples)
        # the first coordinate of the last sample is expected to diverge from zero.
        self.assertFalse(np.isclose(samples[0, 0, -1], 0.))

    def test_john_walk(self):
        d = 2
        (A, b) = pw.define_polytope(d, rep=0)
        r = 0.5
        nb_samples = 10
        nb_iters = 20
        initialization = np.zeros(d)

        samples = pw.run_john_walk(nb_samples, nb_iters, A, b, r)
        self.assertEqual(samples.shape[1], nb_samples)
        # the first coordinate of the last sample is expected to diverge from zero.
        self.assertFalse(np.isclose(samples[0, 0, -1], 0.))
