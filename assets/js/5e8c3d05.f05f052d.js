"use strict";(self.webpackChunkunreal_template_docs=self.webpackChunkunreal_template_docs||[]).push([[894],{3905:(e,t,n)=>{n.d(t,{Zo:()=>u,kt:()=>h});var a=n(7294);function l(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function i(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);t&&(a=a.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,a)}return n}function r(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?i(Object(n),!0).forEach((function(t){l(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):i(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function o(e,t){if(null==e)return{};var n,a,l=function(e,t){if(null==e)return{};var n,a,l={},i=Object.keys(e);for(a=0;a<i.length;a++)n=i[a],t.indexOf(n)>=0||(l[n]=e[n]);return l}(e,t);if(Object.getOwnPropertySymbols){var i=Object.getOwnPropertySymbols(e);for(a=0;a<i.length;a++)n=i[a],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(l[n]=e[n])}return l}var s=a.createContext({}),p=function(e){var t=a.useContext(s),n=t;return e&&(n="function"==typeof e?e(t):r(r({},t),e)),n},u=function(e){var t=p(e.components);return a.createElement(s.Provider,{value:t},e.children)},m="mdxType",d={inlineCode:"code",wrapper:function(e){var t=e.children;return a.createElement(a.Fragment,{},t)}},c=a.forwardRef((function(e,t){var n=e.components,l=e.mdxType,i=e.originalType,s=e.parentName,u=o(e,["components","mdxType","originalType","parentName"]),m=p(n),c=l,h=m["".concat(s,".").concat(c)]||m[c]||d[c]||i;return n?a.createElement(h,r(r({ref:t},u),{},{components:n})):a.createElement(h,r({ref:t},u))}));function h(e,t){var n=arguments,l=t&&t.mdxType;if("string"==typeof e||l){var i=n.length,r=new Array(i);r[0]=c;var o={};for(var s in t)hasOwnProperty.call(t,s)&&(o[s]=t[s]);o.originalType=e,o[m]="string"==typeof e?e:l,r[1]=o;for(var p=2;p<i;p++)r[p]=n[p];return a.createElement.apply(null,r)}return a.createElement.apply(null,n)}c.displayName="MDXCreateElement"},8652:(e,t,n)=>{n.d(t,{Z:()=>i});var a=n(7294),l=n(4996);function i(e){let{src:t,caption:n}=e;return a.createElement("figure",{style:{padding:0}},a.createElement("img",{src:(0,l.Z)(t),alt:n}),a.createElement("figcaption",null,`Figure: ${n}`))}},42:(e,t,n)=>{n.r(t),n.d(t,{assets:()=>p,contentTitle:()=>o,default:()=>d,frontMatter:()=>r,metadata:()=>s,toc:()=>u});var a=n(7462),l=(n(7294),n(3905)),i=n(8652);const r={sidebar_position:2},o="Quick-Start",s={unversionedId:"quickstart/index",id:"quickstart/index",title:"Quick-Start",description:"This document only explains the bare minimum needed to know to get from an API description to a functional Unreal Engine plugin.",source:"@site/docs/quickstart/index.md",sourceDirName:"quickstart",slug:"/quickstart/",permalink:"/template-unreal/quickstart/",draft:!1,editUrl:"https://github.com/apigear-io/template-unreal/edit/main/docs/quickstart/index.md",tags:[],version:"current",lastUpdatedBy:"Wolfgang Bremer",lastUpdatedAt:1676049002,formattedLastUpdatedAt:"Feb 10, 2023",sidebarPosition:2,frontMatter:{sidebar_position:2},sidebar:"docsSidebar",previous:{title:"Introduction",permalink:"/template-unreal/intro"},next:{title:"Features",permalink:"/template-unreal/category/features"}},p={},u=[{value:"1. Install the code generator",id:"1-install-the-code-generator",level:2},{value:"2. Get the template",id:"2-get-the-template",level:2},{value:"Installation via CLI",id:"installation-via-cli",level:3},{value:"Installation via Studio",id:"installation-via-studio",level:3},{value:"Clone from github",id:"clone-from-github",level:3},{value:"3. Set up project",id:"3-set-up-project",level:2},{value:"Solution file",id:"solution-file",level:3},{value:"API module file",id:"api-module-file",level:3},{value:"4. Generate code",id:"4-generate-code",level:2},{value:"Generate via CLI",id:"generate-via-cli",level:3},{value:"Generate via Studio",id:"generate-via-studio",level:3},{value:"5. Use the plugin in your <em>Unreal Engine</em> project",id:"5-use-the-plugin-in-your-unreal-engine-project",level:2},{value:"Blueprint",id:"blueprint",level:3},{value:"C++",id:"c",level:3}],m={toc:u};function d(e){let{components:t,...n}=e;return(0,l.kt)("wrapper",(0,a.Z)({},m,n,{components:t,mdxType:"MDXLayout"}),(0,l.kt)("h1",{id:"quick-start"},"Quick-Start"),(0,l.kt)("p",null,"This document only explains the bare minimum needed to know to get from an API description to a functional ",(0,l.kt)("em",{parentName:"p"},"Unreal Engine")," plugin."),(0,l.kt)("h2",{id:"1-install-the-code-generator"},"1. Install the code generator"),(0,l.kt)("p",null,"Get the ",(0,l.kt)("a",{parentName:"p",href:"https://github.com/apigear-io/studio-releases/releases"},"ApiGear Studio")," or ",(0,l.kt)("a",{parentName:"p",href:"https://github.com/apigear-io/cli-releases/releases"},"ApiGear CLI"),". For more information check the ",(0,l.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/start/install"},"ApiGear documentation"),"."),(0,l.kt)("h2",{id:"2-get-the-template"},"2. Get the template"),(0,l.kt)("p",null,"There are several options to get the template. Installation via the ",(0,l.kt)("em",{parentName:"p"},"Studio")," or the ",(0,l.kt)("em",{parentName:"p"},"CLI"),". Alternatively it is possible to clone, to download from github."),(0,l.kt)("h3",{id:"installation-via-cli"},"Installation via CLI"),(0,l.kt)("p",null,"When using the ",(0,l.kt)("em",{parentName:"p"},"CLI")," only the highlighted line is imported. You can always check whether installation was successful via the ",(0,l.kt)("inlineCode",{parentName:"p"},"template list")," command."),(0,l.kt)("pre",null,(0,l.kt)("code",{parentName:"pre",className:"language-bash"},"$ apigear template list\nlist of templates from registry and cache\nname                       | installed | registry | url\napigear-io/template-unreal | false     | true     | https://github.com/apigear-io/template-unreal.git\n...\n# highlight-next-line\n$ apigear template install apigear-io/template-unreal\n$ apigear template list\nlist of templates from registry and cache\nname                       | installed | registry | url\napigear-io/template-unreal | true      | true     | https://github.com/apigear-io/template-unreal.git\n...\n")),(0,l.kt)("h3",{id:"installation-via-studio"},"Installation via Studio"),(0,l.kt)("p",null,"From within the studio the installation is really simple."),(0,l.kt)("ol",null,(0,l.kt)("li",{parentName:"ol"},"Open an existing project or create an new one"),(0,l.kt)("li",{parentName:"ol"},"Go to the ",(0,l.kt)("inlineCode",{parentName:"li"},"Templates")," tab"),(0,l.kt)("li",{parentName:"ol"},"Click ",(0,l.kt)("inlineCode",{parentName:"li"},"Install")," on the ",(0,l.kt)("inlineCode",{parentName:"li"},"apigear-io/template-unreal")," entry")),(0,l.kt)("h3",{id:"clone-from-github"},"Clone from github"),(0,l.kt)("p",null,"In case you want to check or modify the source code of the template, it is easier to clone or download the repository."),(0,l.kt)("pre",null,(0,l.kt)("code",{parentName:"pre",className:"language-bash"},"$ git clone https://github.com/apigear-io/template-unreal.git\n")),(0,l.kt)("h2",{id:"3-set-up-project"},"3. Set up project"),(0,l.kt)("p",null,"For a project we usually need two files. The solution which specifies what ",(0,l.kt)("inlineCode",{parentName:"p"},"APIs")," and which template to use for it. And at least one ",(0,l.kt)("inlineCode",{parentName:"p"},"API")," module file.\nBot should ideally be in a folder called ",(0,l.kt)("inlineCode",{parentName:"p"},"apigear")," next to each other."),(0,l.kt)("p",null,"Alternatively, you can also use the ",(0,l.kt)("em",{parentName:"p"},"Studio")," to create a new project and modify the two example files."),(0,l.kt)("h3",{id:"solution-file"},"Solution file"),(0,l.kt)("p",null,"Create a ",(0,l.kt)("a",{parentName:"p",href:"https://docs.apigear.io/docs/start/first_steps#create-a-solution"},"solution")," file.\nThe example below specifies"),(0,l.kt)("ul",null,(0,l.kt)("li",{parentName:"ul"},"the ",(0,l.kt)("inlineCode",{parentName:"li"},"helloworld.module.yaml")," which contains the API in ",(0,l.kt)("em",{parentName:"li"},"line 8")),(0,l.kt)("li",{parentName:"ul"},"the output directory in ",(0,l.kt)("em",{parentName:"li"},"line 9")),(0,l.kt)("li",{parentName:"ul"},"the ",(0,l.kt)("inlineCode",{parentName:"li"},"apigear-ui/template-unreal")," to be used in ",(0,l.kt)("em",{parentName:"li"},"line 10"),". This can also be a path to a local copy of the template."),(0,l.kt)("li",{parentName:"ul"},"enables the ",(0,l.kt)("inlineCode",{parentName:"li"},"stubs")," feature of the template, a simple implementation in ",(0,l.kt)("em",{parentName:"li"},"line 13"),". For all available features check the ",(0,l.kt)("a",{parentName:"li",href:"/template-unreal/features/intro"},"overview"),".")),(0,l.kt)("pre",null,(0,l.kt)("code",{parentName:"pre",className:"language-yaml",metastring:'title="helloworld.solution.yaml" showLineNumbers',title:'"helloworld.solution.yaml"',showLineNumbers:!0},'schema: "apigear.solution/1.0"\nname: ue_docs\nversion: "0.1"\n\nlayers:\n  - name: ue_docs\n    inputs:\n      - helloworld.module.yaml\n    output: ../ue_docs\n    template: apigear-io/template-unreal\n    force: true\n    features:\n      - stubs\n')),(0,l.kt)("h3",{id:"api-module-file"},"API module file"),(0,l.kt)("p",null,"Create the ",(0,l.kt)("inlineCode",{parentName:"p"},"helloworld.module.yaml")," with the example content:"),(0,l.kt)("pre",null,(0,l.kt)("code",{parentName:"pre",className:"language-yaml",metastring:'title="helloworld.module.yaml" showLineNumbers',title:'"helloworld.module.yaml"',showLineNumbers:!0},'schema: apigear.module/1.0\nname: io.world\nversion: "1.0"\n\ninterfaces:\n  - name: Hello\n    properties:\n      - { name: last, type: Message }\n    operations:\n      - name: say\n        params:\n          - { name: msg, type: Message }\n          - { name: when, type: When }\n        return:\n          type: int\n    signals:\n      - name: justSaid\n        params:\n          - { name: msg, type: Message }\nenums:\n  - name: When\n    members:\n      - { name: Now, value: 0 }\n      - { name: Soon, value: 1 }\n      - { name: Never, value: 2 }\nstructs:\n  - name: Message\n    fields:\n      - { name: content, type: string }\n')),(0,l.kt)("h2",{id:"4-generate-code"},"4. Generate code"),(0,l.kt)("p",null,"For the code generation we assume that both ",(0,l.kt)("em",{parentName:"p"},"ApiGear")," files reside in an ",(0,l.kt)("inlineCode",{parentName:"p"},"apigear")," subfolder next to the ",(0,l.kt)("em",{parentName:"p"},"Unreal Engine")," project.\nIn this case the folder structure should look similar to this"),(0,l.kt)("pre",null,(0,l.kt)("code",{parentName:"pre",className:"language-bash"},"\ud83d\udce6ue_docs_example_project\n \u2523 \ud83d\udcc2apigear\n \u2503 \u2523 \ud83d\udcdchelloworld.solution.yaml\n \u2503 \u2517 \ud83d\udcdchelloworld.module.yaml\n \u2523 \ud83d\udcc2ue_docs\n \u2503 \u2523 \ud83d\udcc2Config\n \u2503 \u2523 \ud83d\udcc2Content\n \u2503 \u2523 \ud83d\udcc2Platforms\n # highlight-next-line\n \u2503 \u2523 \ud83d\udcc2Plugins\n \u2503 \u2523 \ud83d\udcc2Source\n \u2503 \u2517 \ud83d\udcdcue_docs.uproject\n")),(0,l.kt)("p",null,"With the solution file from the previous paragraph the code will be generated in the ",(0,l.kt)("inlineCode",{parentName:"p"},"ue_docs/Plugins")," folder."),(0,l.kt)("h3",{id:"generate-via-cli"},"Generate via CLI"),(0,l.kt)("p",null,"The following snippet shows how the CLI can be run."),(0,l.kt)("pre",null,(0,l.kt)("code",{parentName:"pre",className:"language-bash"},"$ apigear generate solution apigear/helloworld.solution.yaml \n17:52:20 INF generated 92 files in 30ms. (33 write, 0 skip, 59 copy) topic=gen\n")),(0,l.kt)("ul",null,(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("inlineCode",{parentName:"li"},"generate")," tells the CLI that it should generate code"),(0,l.kt)("li",{parentName:"ul"},(0,l.kt)("inlineCode",{parentName:"li"},"solution")," specifies that we want to run a solution file")),(0,l.kt)("h3",{id:"generate-via-studio"},"Generate via Studio"),(0,l.kt)("ol",null,(0,l.kt)("li",{parentName:"ol"},"Open the project"),(0,l.kt)("li",{parentName:"ol"},"Go to the ",(0,l.kt)("inlineCode",{parentName:"li"},"Solutions")," tab"),(0,l.kt)("li",{parentName:"ol"},"Click ",(0,l.kt)("inlineCode",{parentName:"li"},"Run")," on the ",(0,l.kt)("inlineCode",{parentName:"li"},"helloworld.solution.yaml")," entry")),(0,l.kt)("h2",{id:"5-use-the-plugin-in-your-unreal-engine-project"},"5. Use the plugin in your ",(0,l.kt)("em",{parentName:"h2"},"Unreal Engine")," project"),(0,l.kt)("p",null,"The generated code supports ",(0,l.kt)("em",{parentName:"p"},"Blueprint")," and ",(0,l.kt)("em",{parentName:"p"},"C++")," implementations. The following paragraphs show it can be used.\nMake sure to have the generated plugin code in your projects plugins directory as noted in the ",(0,l.kt)("a",{parentName:"p",href:"#4-generate-code"},"previous section"),"."),(0,l.kt)("h3",{id:"blueprint"},"Blueprint"),(0,l.kt)("p",null,"In ",(0,l.kt)("em",{parentName:"p"},"Blueprint")," we first create an object of the type ",(0,l.kt)("em",{parentName:"p"},"Io World Hello"),". This can then be  directly used or stored in a variable.\nIn the screenshot we use the ",(0,l.kt)("em",{parentName:"p"},"asynchronous say"),' function to say "Hello world".'),(0,l.kt)(i.Z,{caption:"Hello interface blueprint",src:"/img/quick-start-blueprint.png",mdxType:"Figure"}),(0,l.kt)("h3",{id:"c"},"C++"),(0,l.kt)("p",null,"In order to use the plugin code outside of its module we have to add ",(0,l.kt)("em",{parentName:"p"},"IoWorld")," to the list of dependency modules.\nThis can be done like this:"),(0,l.kt)("pre",null,(0,l.kt)("code",{parentName:"pre",className:"language-cs",metastring:'showLineNumbers title="ue_docs.Build.cs"',showLineNumbers:!0,title:'"ue_docs.Build.cs"'},'PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "IoWorld" });\n')),(0,l.kt)("p",null,"Afterwards, we can simply include the header files for the ",(0,l.kt)("inlineCode",{parentName:"p"},"api")," interface, the ",(0,l.kt)("inlineCode",{parentName:"p"},"stub")," implementation and use it.\nThe following code is an example and should not be used like this in production code."),(0,l.kt)("pre",null,(0,l.kt)("code",{parentName:"pre",className:"language-cpp",metastring:'showLineNumbers title="ue_docsGameModeBase.cpp"',showLineNumbers:!0,title:'"ue_docsGameModeBase.cpp"'},'#include "ue_docsGameModeBase.h"\n#include "Implementation/IoWorldHello.h"\n#include "Generated/api/IoWorld_data.h"\n#include "Generated/api/IoWorldHelloInterface.h"\n\nvoid Aue_docsGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)\n{\n    Super::InitGame(MapName,Options, ErrorMessage);\n\n    // Note: UObjects should be referenced from an Unreal type or property, otherwise they might be removed by garbage collection\n    IIoWorldHelloInterface* HelloWorldObjPtr = NewObject<UIoWorldHello>();\n    FIoWorldMessage MyMsg;\n    MyMsg.content = FString("Hello world");\n    HelloWorldObjPtr->Say(MyMsg, EIoWorldWhen::NOW);\n}\n')),(0,l.kt)("admonition",{type:"caution"},(0,l.kt)("p",{parentName:"admonition"},"UObjects should be referenced from an Unreal type or property, otherwise they might be removed by garbage collection.\nFor more information check the ",(0,l.kt)("a",{parentName:"p",href:"https://docs.unrealengine.com/unreal-object-handling-in-unreal-engine/#garbagecollection"},"object handling documentation"),".")))}d.isMDXComponent=!0}}]);