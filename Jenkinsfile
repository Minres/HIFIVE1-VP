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
		sh("conan remote add minres https://api.bintray.com/conan/minres/conan-repo --force")
		sh("conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan --force")
        }
    catch (exc) {
            echo 'Conan configured'
        }
    sh("rm -rf HIFIVE1-VP/build-ubuntu")
    sh("mkdir -p HIFIVE1-VP/build-ubuntu")
    sh("cd HIFIVE1-VP && git submodule update --recursive")
    sh("cd HIFIVE1-VP/build-ubuntu && MAKE_FLAGS='-j4' cmake .. && make -j4")
	fingerprint 'HIFIVE1-VP/build-ubuntu/bin/riscv.vp'
}

void build_hifive_without_scv() {
    try {
        sh("conan profile new default --detect --force")
		sh("conan profile update settings.compiler.libcxx=libstdc++11 default")
		sh("conan remote add minres https://api.bintray.com/conan/minres/conan-repo")
		sh("conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan")
        }
    catch (exc) {
            echo 'Conan configured'
        }
    sh("rm -rf HIFIVE1-VP/build-ubuntu")
    sh("mkdir -p HIFIVE1-VP/build-ubuntu")
    sh("cd HIFIVE1-VP && git submodule update --recursive")
	sh("cd  HIFIVE1-VP/build-ubuntu && MAKE_FLAGS='-j4' cmake .. -DENABLE_SCV=FALSE && make -j4")
	fingerprint 'HIFIVE1-VP/build-ubuntu/bin/riscv.vp'
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
			stage('ubuntu/18.04'){
				agent {docker { image 'ubuntu-18.04' } }
				stages {
					stage('Checkout on Ubuntu') {
						steps {
							checkout_hifive_vp()
						}
					}
					stage('Build on Ubuntu') {
						steps {
							build_hifive_vp()
						}
					}
				}
			}
			stage('Fedora/28'){
				agent {docker { image 'fedora28' } }
				stages {
					stage('Checkout on Fedora') {
						steps {
							checkout_hifive_vp()
						}
					}
					stage('Build on Fedora') {
						steps {
							build_hifive_vp()
						}
					}
				}
			}
			stage('Build without SCV'){
				agent {docker { image 'ubuntu-18.04' } }
				stages {
					stage('Checkout on Ubuntu') {
						steps {
							checkout_hifive_vp()
						}
					}
					stage('Build without SCV') {
						steps {
							build_hifive_without_scv()
						}
					}
				}
			}

 		}
        }
	}
}
