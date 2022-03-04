#include "ast.hpp"

#include <string>
#include <regex>

static int makeNameUnq=0;

static std::string makeName(std::string base)
{
    return "_"+base+"_"+std::to_string(makeNameUnq++);
}

void CompileRec(
    std::string destReg,    // The name of the register to put the result in
    TreePtr program
){
    std::regex reNum("^-?[0-9]+$");
    std::regex reId("^[a-z][a-z0-9]*$");
    
    if( regex_match( program->type, reNum ) ){                                  
        std::cout<<"const "<<destReg<<" "<<program->type<<std::endl;
        
    }else if( regex_match( program->type, reId ) ){                             
        std::string zero = makeName("zero");
        std::cout<<"const "<< zero <<" 0"<<std::endl;
        std::cout << "add "<< destReg << " " << program->type << " " << zero << std::endl;

    }else if(program->type=="Assign"){
        CompileRec(program->value, program->branches.at(0));
        
    }else if(program->type=="Output"){
        CompileRec(destReg, program->branches[0]);
        std::cout << "output " << destReg << std::endl;

    }else if(program->type=="Input"){
        std::cout<<"input " << destReg << std::endl;

    }else if(program->type=="LessThan"){
        std::string srcRegA = makeName("srcRegA");
        std::string srcRegB = makeName("srcRegB");
        CompileRec(srcRegA, program->branches.at(0));
        CompileRec(srcRegB, program->branches.at(1));
        std::cout << "lt " << destReg << " " << srcRegA << " " << srcRegB <<std::endl;

    }else if(program->type=="Add"){
        std::string srcRegA = makeName("srcRegA");
        std::string srcRegB = makeName("srcRegB");
        CompileRec(srcRegA, program->branches.at(0));
        CompileRec(srcRegB, program->branches.at(1));
        std::cout << "add " << destReg << " " << srcRegA << " " << srcRegB <<std::endl;

    }else if(program->type=="Sub"){
        std::string srcRegA = makeName("srcRegA");
        std::string srcRegB = makeName("srcRegB");
        CompileRec(srcRegA, program->branches.at(0));
        CompileRec(srcRegB, program->branches.at(1));
        std::cout << "sub " << destReg << " " << srcRegA << " " << srcRegB <<std::endl;

    }else if(program->type=="If"){
        std::string if_s = makeName("if");
        std::string else_s = makeName("else");
        std::string end_s = makeName("end");

        std::string cond_tmp = makeName("cond");

        CompileRec(cond_tmp, program->branches.at(0));

        std::cout<<"bne " << cond_tmp << " zero " << if_s << std::endl;
        std::cout<<"beq " << cond_tmp << " zero " << else_s << std::endl;

        std::cout << ":" << if_s << std::endl;
        CompileRec(destReg, program->branches.at(1));
        std::cout << "beq zero zero " << end_s << std::endl;

        std::cout << ":" << else_s << std::endl;
        CompileRec(destReg, program->branches.at(2));

        std::cout << ":" << end_s << std::endl;

    }else if(program->type=="While"){
        std::string top = makeName("top");
        std::string bottom = makeName("bottom");

        std::cout << ":" << top << std::endl;
        std::string tmp = makeName("tmp");
        // check condition
        // branch to end if condition true.
        CompileRec(destReg, program->branches.at(0));
        std::cout<<"beq " << destReg << " zero " << bottom << std::endl;
        // cal code we want to do:
        CompileRec(tmp, program->branches.at(1));
        // Branch to top
        //std::cout<<"beq " << program->branches.at(0)->type << " " << program->branches.at(0)->type << " top" << std::endl;
        std::cout<<"beq zero zero " << top << std::endl;
        std::cout << ":" << bottom << std::endl;

    }else{
        throw std::runtime_error("Unknown construct '"+program->type+"'");
    }
}

void Compile(
    TreePtr program
){
    // Create a register to hold the final result
    std::string res=makeName("res");
    
    // Compile the whole thing
    std::cout << "const zero 0" << std::endl;
    
    for(unsigned i = 0; i < program->branches.size(); i++){
        CompileRec(res, program->branches[i]);
    }
    
    // Put the result out
    std::cout<<"halt "<<res<<"\n";
}
