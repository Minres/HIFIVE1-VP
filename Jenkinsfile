node {
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
    stage('build VP ubuntu/18.04'){
		def ubuntu = docker.image('ubuntu-18.04')
		ubuntu.inside('-u jenkins') {
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
            sh("cd HIFIVE1-VP/build-ubuntu && MAKE_FLAGS='-j4' cmake .. && make -j4")
			fingerprint 'HIFIVE1-VP/build-ubuntu/bin/riscv.vp'
		}
	}
	stage('build VP fedora/28'){
		def centos = docker.image('fedora28')
		centos.inside('-u jenkins') {
            try {
                sh("conan profile new default --detect --force")
		        sh("conan profile update settings.compiler.libcxx=libstdc++11 default")
		        sh("conan remote add minres https://api.bintray.com/conan/minres/conan-repo")
		        sh("conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan")
            }
            catch (exc) {
                echo 'Conan configured'
            }
            sh("rm -rf HIFIVE1-VP/build-fedora")
            sh("mkdir HIFIVE1-VP/build-fedora")
			sh("cd HIFIVE1-VP/build-fedora && MAKE_FLAGS='-j4' cmake .. && make -j4")
			fingerprint 'HIFIVE1-VP/build-fedora/bin/riscv.vp'
		}
	}
    stage('build VP without SCV'){
		def ubuntu = docker.image('ubuntu-18.04')
		ubuntu.inside('-u jenkins') {
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
	}
}
