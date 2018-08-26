#include "dikin_walker.hpp"
#include "vaidya_walker.hpp"
#include "john_walker.hpp"


Eigen::MatrixXd generateDikinWalkSamples(const Eigen::VectorXd& initialization, const Eigen::MatrixXd& cons_A, const Eigen::VectorXd& cons_b, const double r, const int nb_samples){

    Eigen::MatrixXd samples = Eigen::MatrixXd::Zero(cons_A.cols(), nb_samples);

    pwalk::DikinWalker<double> dikinw = pwalk::DikinWalker<double>(initialization, cons_A, cons_b, r);

    Eigen::VectorXd new_sample = Eigen::VectorXd::Zero(cons_A.cols());

    for (int i = 0; i < nb_samples; ++i) {
        dikinw.doSample(new_sample);
        samples.col(i) = new_sample;
    }

    return samples;
}

Eigen::MatrixXd generateVaidyaWalkSamples(const Eigen::VectorXd& initialization, const Eigen::MatrixXd& cons_A, const Eigen::VectorXd& cons_b, const double r, const int nb_samples){

    Eigen::MatrixXd samples = Eigen::MatrixXd::Zero(cons_A.cols(), nb_samples);

    pwalk::VaidyaWalker<double> vaidyaw = pwalk::VaidyaWalker<double>(initialization, cons_A, cons_b, r);

    Eigen::VectorXd new_sample = Eigen::VectorXd::Zero(cons_A.cols());

    for (int i = 0; i < nb_samples; ++i) {
        vaidyaw.doSample(new_sample);
        samples.col(i) = new_sample;
    }

    return samples;
}

Eigen::MatrixXd generateJohnWalkSamples(const Eigen::VectorXd& initialization, const Eigen::MatrixXd& cons_A, const Eigen::VectorXd& cons_b, const double r, const int nb_samples){

    Eigen::MatrixXd samples = Eigen::MatrixXd::Zero(cons_A.cols(), nb_samples);

    pwalk::JohnWalker<double> johnw = pwalk::JohnWalker<double>(initialization, cons_A, cons_b, r);

    Eigen::VectorXd new_sample = Eigen::VectorXd::Zero(cons_A.cols());

    for (int i = 0; i < nb_samples; ++i) {
        johnw.doSample(new_sample);
        samples.col(i) = new_sample;
    }

    return samples;
}

