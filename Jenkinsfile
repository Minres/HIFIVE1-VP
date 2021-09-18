void checkout_hifive_vp() {
    checkout([
        $class: 'GitSCM',
        branches: [[name: '*/develop']],
        browser: [$class: 'GogsGit', repoUrl: ''],
        doGenerateSubmoduleConfigurations: false,
        extensions: [
            [
                $class: 'SubmoduleOption',
                disableSubmodules: false,
                parentCredentials: false,
                recursiveSubmodules: true,
                reference: '',
                trackingSubmodules: true
            ],
            [$class: 'CleanBeforeCheckout'],
            [$class: 'WipeWorkspace'],
            [$class: 'RelativeTargetDirectory', relativeTargetDir: 'HIFIVE1-VP']
        ],
        submoduleCfg: [],
        userRemoteConfigs: [[
            credentialsId: 'gitea-jenkins',
            url: 'https://git.minres.com/VP/HIFIVE1-VP.git'
        ]]
    ])
}

void build_hifive_vp() {
    try {
        sh("conan profile new default --detect --force")
        sh("conan profile update settings.compiler.libcxx=libstdc++11 default")
        sh("conan remote add minres https://artifactory.minres.com/artifactory/api/conan/oss --force")
        sh("cmake --version")
    }
    catch (exc) {
        echo 'Conan configured'
    }
    sh("rm -rf HIFIVE1-VP/build")
    sh("mkdir -p HIFIVE1-VP/build")
    sh("cd HIFIVE1-VP && git submodule update --recursive")
    sh("cd HIFIVE1-VP/build && MAKE_FLAGS='-j4' cmake .. && make -j4")
    fingerprint 'HIFIVE1-VP/build/bin/riscv.vp'
}

void build_hifive_without_scv() {
    try {
        sh("conan profile new default --detect --force")
        sh("conan profile update settings.compiler.libcxx=libstdc++11 default")
        sh("conan remote add minres https://artifactory.minres.com/artifactory/api/conan/oss --force")
        sh("cmake --version")
    }
    catch (exc) {
        echo 'Conan configured'
    }
    sh("rm -rf HIFIVE1-VP/build")
    sh("mkdir -p HIFIVE1-VP/build")
    sh("cd HIFIVE1-VP && git submodule update --recursive")
    sh("cd  HIFIVE1-VP/build && MAKE_FLAGS='-j4' cmake .. -DENABLE_SCV=FALSE && make -j4")
    fingerprint 'HIFIVE1-VP/build/bin/riscv.vp'
}


pipeline {
    agent none

    options { 
        // using the Timestamper plugin we can add timestamps to the console log
        timestamps() 
        skipStagesAfterUnstable() 
    }

    stages {
        stage('HiFive-VP pipeline') {
           parallel {
            stage('ubuntu18'){
                agent {docker { image 'ubuntu-18.04' } }
                stages {
                    stage('Checkout on Ubuntu18.04') { steps {    checkout_hifive_vp() }}
                    stage('Build') { steps {    build_hifive_vp() }    }
                }
            }
            stage('ubuntu20'){
                agent {docker { image 'ubuntu-20.04' } }
                stages {
                    stage('Checkout on Ubuntu20.04') { steps {    checkout_hifive_vp() }}
                    stage('Build') { steps {    build_hifive_vp() }    }
                }
            }
            stage('Fedora28'){
                agent {docker { image 'fedora28' } }
                stages {
                    stage('Checkout on Fedora') { steps {checkout_hifive_vp()}}
                    stage('Build') { steps {build_hifive_vp()    }}
                }
            }
            stage('No SCV'){
                agent {docker { image 'ubuntu-18.04' } }
                stages {
                    stage('Checkout on Ubuntu') { steps {checkout_hifive_vp()}}
                    stage('Build without SCV') { steps {build_hifive_without_scv()}
                    }
                }
            }
         }
        }
    }
}
