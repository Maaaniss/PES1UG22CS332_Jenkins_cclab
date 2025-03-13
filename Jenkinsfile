pipeline {
  agent any
  stages {
    stage('Build'){
      steps {
        build 'PES1UG22CS332-1'
        sh 'g++ cpp.cpp -o cpp'
      }

    }
    stage('Test'){
      steps {
        sh './cpp'
      }
    }
    stage('Deploy'){
      steps{
        echo 'Deployed'
      }
    }
  }
  post{
    failure{
      error 'Pipeline failed'
    }
  }
}
