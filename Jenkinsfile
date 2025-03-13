pipeline {
  agent any
  stages {
    stage('Build'){
      steps {
        build 'PES1UG22CS332-1'
        sh 'g++ hello1.cpp -o hello1'
      }

    }
    stage('Test'){
      steps {
        sh './hello1'
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
