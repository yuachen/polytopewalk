import numpy as np
import time

import pwalk


def define_polytope(d, rep=0):
    A1 = np.eye(d)
    A2 = -np.eye(d)
    b1 = np.ones(d) * 1.
    b2 = np.zeros(d) + 1

    A = np.concatenate((A1, A2), axis=0)
    b = np.concatenate((b1, b2), axis=0)

    for _ in range(rep):
        A = np.concatenate((A, A), axis=0)
        b = np.concatenate((b, b), axis=0)

    return A, b


def run_dikin_walk(experiments, iterations, A, b, r):
    _, d = A.shape
    rvs = np.zeros((d, experiments, iterations))
    t0 = time.time()

    for exp in range(experiments):

        # Initialization
        x0 = 0.2 * np.random.randn(d)
        while np.any(A.dot(x0) > b):
            x0 = 0.2 * np.random.randn(d)

        # Dikin Iterations
        rvs[:, exp, 0] = x0  # np.array([0., 0.])
        rvs[:, exp, 1:] = pwalk.generateDikinWalkSamples(x0, A, b, r, iterations-1)
        # Profiling
        t1 = time.time()
        if exp % (experiments / 10) == 0:
            print 'Experiment Number: %d, Time Taken: %.2f' % (exp, t1 - t0)
            t0 = t1
    return rvs

def run_vaidya_walk(experiments, iterations, A, b, r):
    _, d = A.shape
    rvs = np.zeros((d, experiments, iterations))
    t0 = time.time()

    for exp in range(experiments):

        # Initialization
        x0 = 0.2 * np.random.randn(d)
        while np.any(A.dot(x0) > b):
            x0 = 0.2 * np.random.randn(d)

        # Dikin Iterations
        rvs[:, exp, 0] = x0  # np.array([0., 0.])
        rvs[:, exp, 1:] = pwalk.generateVaidyaWalkSamples(x0, A, b, r, iterations-1)
        # Profiling
        t1 = time.time()
        if exp % (experiments / 10) == 0:
            print 'Experiment Number: %d, Time Taken: %.2f' % (exp, t1 - t0)
            t0 = t1
    return rvs


def run_john_walk(experiments, iterations, A, b, r):
    _, d = A.shape
    rvs = np.zeros((d, experiments, iterations))
    t0 = time.time()

    for exp in range(experiments):

        # Initialization
        x0 = 0.2 * np.random.randn(d)
        while np.any(A.dot(x0) > b):
            x0 = 0.2 * np.random.randn(d)

        # Dikin Iterations
        rvs[:, exp, 0] = x0  # np.array([0., 0.])
        rvs[:, exp, 1:] = pwalk.generateJohnWalkSamples(x0, A, b, r, iterations-1)
        # Profiling
        t1 = time.time()
        if exp % (experiments / 10) == 0:
            print 'Experiment Number: %d, Time Taken: %.2f' % (exp, t1 - t0)
            t0 = t1
    return rvs

