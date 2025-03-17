#include "action.hh"
#include "SteppingAction.hh"
#include "EventAction.hh"
#include "RunAction.hh"
#include "StackingAction.hh"


namespace placeholder
{

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{
	
}
	
void MyActionInitialization::BuildForMaster() const
{
	RunAction *runAction = new RunAction;
	//std::unique_ptr<RunAction> runAction(new RunAction());
	SetUserAction(runAction);	
	
}


void MyActionInitialization::Build() const
{
	MyPrimaryGenerator *generator = new MyPrimaryGenerator();
	//std::unique_ptr<MyPrimaryGenerator>generator = std::make_unique<MyPrimaryGenerator>();
	SetUserAction(generator);
	
	RunAction *runAction = new RunAction;
	//std::unique_ptr<RunAction>runAction = std::make_unique<RunAction>();
	SetUserAction(runAction);
	
	EventAction *eventAction = new EventAction(runAction);
	//std::unique_ptr<EventAction>eventAction = std::make_unique<EventAction>(runAction);
	SetUserAction(eventAction);
	
	SteppingAction *steppingAction = new SteppingAction(eventAction);
	//std::unique_ptr<SteppingAction>steppingAction = std::make_unique<SteppingAction>(eventAction);
	SetUserAction(steppingAction);
	
	StackingAction *stackingAction = new StackingAction;
	//std::unique_ptr<StackingAction>stackingAction = std::make_unique<StackingAction>()
	SetUserAction(stackingAction);
	
	
		
}

}
